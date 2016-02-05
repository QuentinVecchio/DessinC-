/*************************************************************************
                           SetOfFigures  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio 
*************************************************************************/

//---------- Interface de la classe <SetOfFigures> (fichier SetOfFigures.h) ------
#if ! defined ( SETOFFIGURES_H )
#define SETOFFIGURES_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <map>
#include "Vect.h"
#include "Figure.h"

using namespace std;


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <SetOfFigures>
//  La classe SetOfFigures est une classe abstraite qui permet de représenter un
//  ensemble de figure.
//
//------------------------------------------------------------------------ 

class SetOfFigures : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    map<string, Figure*> GetFigures() const;
    // Mode d'emploi :
    //  Cette méthode renvoie un ensemble de figure
    // Contrat :
    //  

    void SetFigures( const map<string, Figure*> &ens );
    // Paramètre
    //  ens : ensemble de figure
    // Mode d'emploi :
    //  Modification de l'ensemble de figure
    // Contrat :
    //

    bool Add(Figure *f);
    // Paramètre
    //  name : nom de la figure
    //  f : nouvelle figure
    // Mode d'emploi :
    //  Ajout d'une figure
    //  True si l'ajout s'est fait, False sinon
    // Contrat :
    //

    virtual bool Remove(const string &name);
    // Paramètre
    //  name : nom de la figure
    // Mode d'emploi :
    //  Suppression d'une figure
    //  True si la suppression s'est faite, False sinon
    //  Méthode virtuel
    // Contrat :
    //

    void RemoveAll();
    // Mode d'emploi :
    //  Suppression de toutes les figures
    // Contrat :
    //

    Figure* GetFigure(const string &name) const;
    // Paramètre
    //  name : nom de la figure
    // Mode d'emploi :
    //  Renvoie la figure associé au nom
    // Contrat :
    //

    virtual string Print() const;
    // Mode d'emploi :
    //  Méthode qui affiche un SetOfFigures
    // Contrat :
    //

    virtual bool IsIn( const Vect &p ) const = 0;
    // Paramètre
    //  p : Vect pour lequel on veut savoir si il fait partie de la SetOfFigures
    // Mode d'emploi :
    //  Méthode qui test si un Vect appartient à une SetOfFigures
    //  TRUE si le Vect appartient, FALSE sinon
    //  Méthode virtuel 
    // Contrat :
    //


    SetOfFigures* Copy( ) const = 0;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //
    
    void Move( const Vect &p );
    // Paramètre
    //  p : Vect de déplacement
    // Mode d'emploi :
    //  Méthode qui fait bouger une SetOfFigures
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    virtual ~SetOfFigures ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
    SetOfFigures ( const SetOfFigures & uneSetOfFigures );
    //Paramètre
    //  uneSetOfFigures : unSetOfFigures déjà initialisée
    // Mode d'emploi (constructeur de copie) :
    //  Constructeur protégée car la classe est abstraite
    // Contrat :
    //

    SetOfFigures ( const string & name);
    // Mode d'emploi :
    //  Constructeur protégée car la classe est abstraite
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    map<string, Figure *> figures;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SetOfFigures>

#endif // SETOFFIGURES_H
