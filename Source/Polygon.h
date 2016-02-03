/*************************************************************************
                           Polygon  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Polygon> (fichier Polygon.h) ------
#if ! defined ( Polygon_H )
#define Polygon_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Vect.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Polygon>
//
//
//------------------------------------------------------------------------

class Polygon : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	string Print() const;
	// Mode d'emploi :
    //	Méthode qui affiche une figure
	//	Méthode virtuel
    // Contrat :
    //

	bool IsIn( const Vect &p ) const;
	// Paramètre
	//	p : Vect pour lequel on veut savoir si il fait partie de la figure
	// Mode d'emploi :
    //	Méthode qui test si un Vect appartient à une figure
	//	TRUE si le Vect appartient, FALSE sinon
	//	Méthode virtuel
    // Contrat :
    //

	void Move( const Vect &p );
	// Paramètre
	//	p : Vect de déplacement
	// Mode d'emploi :
    //	Méthode qui fait bouger une figure
	//	Méthode virtuel
    // Contrat :
    //

    Polygon* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel
    // Contrat :
    //

    bool InitPoy( const vector<Vect> & aListPoint);

	Vect GetP1 ();
	Vect GetP2 ();
	void SetP1 ();
	void SetP2 ();


//------------------------------------------------- Surcharge d'opérateurs
    Polygon & operator = ( const Polygon & unPolygon );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polygon ( const Polygon & aPolygon );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polygon (string nom );
    // Mode d'emploi :
    //
    // Contrat :
    //


    virtual ~Polygon ( );
    // Mode d'emploi :
    //
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
    vector<Vect> listePoints;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polygon>

#endif // Polygon_H
