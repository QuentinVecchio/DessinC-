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
#include "SetOfFigures.h"
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Dessin>
//  La classe Dessin permet le stockage de figure ainsi que l'application de fonction dessus
//
//------------------------------------------------------------------------ 

class Dessin : public SetOfFigures
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string Print() const;
    // Mode d'emploi :
    //  Méthode qui affiche toutes les figures d'un dessin
    //  Méthode virtuel 
    // Contrat :
    //

    bool AddByCmd(const string &cmd);
    // Paramètre
    //  cmd : commande de creation
    // Mode d'emploi :
    //  Méthode qui ajoute une figure grâce à une ligne de commande
    //  TRUE si la figure a été ajoutée, FALSE sinon
    // Contrat :
    //

    bool IsIn( const Vect &p ) const;
    // Paramètre
    //  p : Vect pour lequel on veut savoir si il fait partie d'une figure
    // Mode d'emploi :
    //  Méthode qui test si un Vect appartient à un dessin
    //  TRUE si le Vect appartient, FALSE sinon
    // Contrat :
    //

	bool IsInFigure( const string & name, const Vect &p ) const;
	// Paramètre
	//	name : nom de la figure dans laquelle on veut faire le test
	//	p : Vect pour lequel on veut savoir si il fait partie d'une figure
	// Mode d'emploi :
    //	Méthode qui test si un Vect appartient à une figure
	//	TRUE si le Vect appartient, FALSE sinon
	//	Méthode virtuel 
    // Contrat :
    //

	void MoveFigure( const string & name, const Vect &p);
	// Paramètre
	//	name : nom de la figure que l'on veut déplacer
	//	p : Vect de déplacement
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

	bool Load(const string &link);
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

    Dessin* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

    bool AddByLoad( const string &donnees, SetOfFigures *conteneur, fstream *fichier);
    // Mode d'emploi :
    //  Ajout d'une nouvelle figure directement depuis un fichier
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
	Dessin & operator = ( const Dessin & unDessin );
    // Mode d'emploi :
    //
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

    Dessin ( const string &name );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Dessin>

#endif // DESSIN_H
