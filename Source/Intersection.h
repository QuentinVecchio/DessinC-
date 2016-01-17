/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <Intersection> (fichier Intersection.h) ------
#if ! defined ( Intersection_H )
#define Intersection_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <map>
#include "Figure.h"
#include "SetOfFigures.h"
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Intersection>
//  La classe Intersection permet le stockage d'une Intersection de figures ainsi que l'application de fonction dessus
//
//------------------------------------------------------------------------ 

class Intersection : public SetOfFigures
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual string Print() const;
    // Mode d'emploi :
    //  Méthode qui affiche toutes les figures d'un Intersection
    //  Méthode virtuel 
    // Contrat :
    //

    virtual bool IsIn( const Point &p ) const;
    // Paramètre
    //  p : point pour lequel on veut savoir si il fait partie d'une figure
    // Mode d'emploi :
    //  Méthode qui test si un point appartient à un Intersection
    //  TRUE si le point appartient, FALSE sinon
    // Contrat :
    //

    virtual Intersection* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
	Intersection & operator = ( const Intersection & unIntersection );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	Intersection ( const Intersection & unIntersection );
	//Paramètre
	//	unIntersection : Intersection déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //	
    // Contrat :
    //

    Intersection ( const string &name );
    // Mode d'emploi :
    //	Constructeur de la classe Intersection
    // Contrat :
    //

    virtual ~Intersection ( );
    // Mode d'emploi :
    //	Détruit toutes les figures
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Intersection>

#endif // Intersection_H
