/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <Dessin> (fichier Dessin.h) ------
#if ! defined ( DESSIN_H )
#define DESSIN_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <map>
#include "Figure.h"

using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Dessin>
//
//
//------------------------------------------------------------------------ 

class Dessin
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	map<string, Figure*> GetFigures() const;
	// Mode d'emploi :
    //	Cette méthode renvoie le map contenant toutes les figures
    // Contrat :
    //	

	void SetFigures( const map<string, Figure *> &figures );
	//Paramètre :
	//	figures : map contenant des pointeurs sur figure
	// Mode d'emploi :
    //	Cette méthode modifie le map de figures
    // Contrat :
    //

	Figure * GetFigure( const string &n ) const;
	//Paramètre :
	//	n : nom de la figure
	// Mode d'emploi :
    //	Cette méthode renvoie la figure correspondante au nom
	//	Renvoie NULL si la méthde n'existe pas
    // Contrat :
    //

	bool AddFigure( const string &donnees );
	//Paramètre :
	//	type : type de la figure
	//	donnees : données pour la construction de la figure
	// Mode d'emploi :
    //	Cette méthode crée une nouvelle figure
	//	Renvoie TRUE si la figure a bien été créée, renvoie FALSE sinon
    // Contrat :
    //

	bool DeleteFigure( const string &n );
	// Mode d'emploi :
    //	Cette méthode supprime la figure correspondante au nom
	//	Renvoie TRUE si la figure a bien été supprimée, renvoie FALSE snion
    // Contrat :
    //

	string Print() const;
	// Mode d'emploi :
    //	Méthode qui affiche les figures composant un Dessin
	//	Méthode virtuel 
    // Contrat :
    //

	bool IsIn( const string & name, const Point &p ) const;
	// Paramètre
	//	name : nom de la figure dans laquelle on veut faire le test
	//	p : point pour lequel on veut savoir si il fait partie d'une figure
	// Mode d'emploi :
    //	Méthode qui test si un point appartient à une figure
	//	TRUE si le point appartient, FALSE sinon
	//	Méthode virtuel 
    // Contrat :
    //

	void Move( const string & name, const Point &p);
	// Paramètre
	//	name : nom de la figure que l'on veut déplacer
	//	p : point de déplacement
	// Mode d'emploi :
    //	Méthode qui déplace une figure
    // Contrat :
    //

	bool Save(const string &link);
	// Parametre
	//	link : lien vers le fichier
	// Mode d'emploi :
    //	Méthode qui permet de sauvegarder un dessin directement dans un fichier
    // Contrat :
    //

	void Load(const string &link);
	// Parametre
	//	link : lien vers le fichier
	// Mode d'emploi :
    //	Méthode qui permet de créer un dessin directement depuis un fichier
    // Contrat :
    //

	void Undo();
	// Mode d'emploi :
    //	Méthode qui permet de revenir en arrière après une modification
	//	Limité à 20 fois
    // Contrat :
    //

	void Redo();
	// Mode d'emploi :
    //	Méthode qui permet de revenir en avant une modification
	//	Limité à 20 fois
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
	Dessin & operator = ( const Dessin & unDessin );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	friend ostream& operator<<( ostream& out, const Dessin &d );
	// Mode d'emploi :
    //	Méthode qui surcharge l'affichage
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	Dessin ( const Dessin & unDessin );
	//Paramètre
	//	unDessin : Dessin déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //	
    // Contrat :
    //

    Dessin ( );
    // Mode d'emploi :
    //	Constructeur de la classe Dessin
    // Contrat :
    //

    virtual ~Dessin ( );
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
	map<string,Figure *> figures;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Dessin>

#endif // DESSIN_H
