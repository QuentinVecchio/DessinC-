/*************************************************************************
                           Polygon  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio
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

	int GetNbPoints() const;
    // Mode d'emploi :
    //  Méthode qui renvoie le nombre de point dans le polygone
    // Contrat :
    //

    bool IsConvexe() const;
    // Mode d'emploi :
    //  Méthode qui renvoie TRUE si le polygone est connexe, FALSE sinon
    // Contrat :
    //

    void Add(const Vect &p);
    // Paramètre
    //  p : nouveau point
    // Mode d'emploi :
    //  Méthode qui ajoute un point au polygone
    // Contrat :
    //

    vector<Vect> GetPoints() const;
    // Mode d'emploi :
    //  Méthode qui renvoie tous les points du polygone
    // Contrat :
    //

    void SetPoints(const vector<Vect> &list);
    // Paramètre
    //  list : liste de point
    // Mode d'emploi :
    //  Méthode qui modifie tous les points du polygone
    // Contrat :
    //

    void RemoveAll();
    // Mode d'emploi :
    //  Supprime tous les points d'un polygone
    // Contrat :
    //

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

    Polygon ( string nom );
    // Paramètre
    //  nom : nom du polygone
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
