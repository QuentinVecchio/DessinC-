/*************************************************************************
                           Union  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <Union> (fichier Union.h) ------
#if ! defined ( UNION_H )
#define UNION_H

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
// Rôle de la classe <Union>
//  La classe Union permet le stockage d'une union de figures ainsi que l'application de fonction dessus
//
//------------------------------------------------------------------------ 

class Union : public SetOfFigures
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual string Print() const;
    // Mode d'emploi :
    //  Méthode qui affiche toutes les figures d'un Union
    //  Méthode virtuel 
    // Contrat :
    //

    virtual bool IsIn( const Vect &p ) const;
    // Paramètre
    //  p : Vect pour lequel on veut savoir si il fait partie d'une figure
    // Mode d'emploi :
    //  Méthode qui test si un Vect appartient à un Union
    //  TRUE si le Vect appartient, FALSE sinon
    // Contrat :
    //

    virtual Union* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
	Union & operator = ( const Union & unUnion );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	Union ( const Union & unUnion );
	//Paramètre
	//	unUnion : Union déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //	
    // Contrat :
    //

    Union ( const string &name );
    // Mode d'emploi :
    //	Constructeur de la classe Union
    // Contrat :
    //

    virtual ~Union ( );
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

//----------------------------------------- Types dépendants de <Union>

#endif // UNION_H
