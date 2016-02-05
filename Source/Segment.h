/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio 
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier Segment.h) ------
#if ! defined ( Segment_H )
#define Segment_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Vect.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Segment>
//
//
//------------------------------------------------------------------------

class Segment : public Figure
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

    Segment* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel
    // Contrat :
    //


	Vect GetP1 ( ) const;
    // Mode d'emploi :
    //  Renvoie le point p1 du segment
    // Contrat :
    //

	Vect GetP2 ( ) const;
    // Mode d'emploi :
    //  Renvoie le point p1 du segment
    // Contrat :
    //

	void SetP1 ( const Vect &v );
    // Paramètre
    //  v : nouveau point
    // Mode d'emploi :
    //  Méthode qui modifie le point 1
    // Contrat :
    //

	void SetP2 ( const Vect &v );
    // Paramètre
    //  v : nouveau point
    // Mode d'emploi :
    //  Méthode qui modifie le point 2
    // Contrat :
    //

    float GetLength() const;
    // Mode d'emploi :
    //  Méthode qui renvoie la taille d'un segment
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Segment & operator = ( const Segment & unSegment );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & aSegment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Segment (string nom, int x1, int y1, int x2, int y2 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Segment (string nom, Vect p1, Vect p2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Segment ( );
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
    Vect p1;
    Vect p2;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Segment>

#endif // Segment_H
