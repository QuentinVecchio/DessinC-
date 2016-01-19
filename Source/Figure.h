/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include "Vect.h"
using namespace std;


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Figure>
//	La classe figure est une classe abstraite qui permet de représenter une
//	figure.
//
//------------------------------------------------------------------------ 

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	string GetName() const;
	// Mode d'emploi :
    //	Cette méthode renvoie le nom d'une figure
    // Contrat :
    //	

	void SetName( const string &s );
	// Paramètre
	//	s : nouveau nom de la figure
	// Mode d'emploi :
    //	Modification du nom d'une figure
    // Contrat :
    //

	virtual string Print() const;
	// Mode d'emploi :
    //	Méthode qui affiche une figure
	//	Méthode virtuel 
    // Contrat :
    //

	virtual bool IsIn( const Vect &p ) const = 0;
	// Paramètre
	//	p : Vect pour lequel on veut savoir si il fait partie de la figure
	// Mode d'emploi :
    //	Méthode qui test si un Vect appartient à une figure
	//	TRUE si le Vect appartient, FALSE sinon
	//	Méthode virtuel 
    // Contrat :
    //
	
	virtual void Move( const Vect &p ) = 0;
	// Paramètre
	//	p : Vect de déplacement
	// Mode d'emploi :
    //	Méthode qui fait bouger une figure
	//	Méthode virtuel 
    // Contrat :
    //

    virtual Figure* Copy( ) const = 0;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
	friend ostream& operator<<(ostream& out, const Figure &f);
	// Mode d'emploi :
    //	Méthode qui surcharge l'affichage
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	Figure ( const Figure & uneFigure );
	//Paramètre
	//	uneFigure : figure déjà initialisée
    // Mode d'emploi (constructeur de copie) :
    //	Constructeur protégée car la classe est abstraite
    // Contrat :
    //

    Figure ( const string &n );
	//Paramètre
	//	n : nom d'une figure
    // Mode d'emploi :
    //	Constructeur protégée car la classe est abstraite
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
	string name;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Figure>

#endif // FIGURE_H
