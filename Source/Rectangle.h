/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 16/01/2016
    copyright            : (C) 2016 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Point.h"
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Rectangle>
//  La classe Rectangle modélise un rectangle avec deux points
//
//------------------------------------------------------------------------

class Rectangle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetWeight() const;
    // Mode d'emploi :
    //  Renvoie la largeur du rectangle
    // Contrat :
    //

    int GetLength() const;
    // Mode d'emploi :
    //  Renvoie la longeur du rectangle
    // Contrat :
    //

    Point GetP1() const;
    // Mode d'emploi :
    //  Renvoie le point 1 du rectangle
    // Contrat :
    //

    void SetP1( const Point &p );
    // Paramètre :
    //  p : nouveau point
    // Mode d'emploi :
    //  Modifie le point 1 du rectangle
    // Contrat :
    //

    Point GetP2() const;
    // Mode d'emploi :
    //  Renvoie le point 1 du rectangle
    // Contrat :
    //

    void SetP2( const Point &p );
    // Paramètre : 
    //  p : nouveau point
    // Mode d'emploi :
    //  Modifie le point 1 du rectangle
    // Contrat :
    //

    virtual string Print() const;
    // Mode d'emploi :
    //  Renvoie un string contenant toutes les informations d'un rectangle
    // Contrat :
    //

    virtual bool IsIn( const Point &point ) const;
    // Paramètre :
    //  point : point a tester
    // Mode d'emploi :
    //  Renvoie TRUE si le point fait partie du rectangle
    // Contrat :
    //

    virtual void Move( const Point &point );
    // Paramètre :
    //  point : point de deplacement
    // Mode d'emploi :
    //  Modifie les coordonnées du rectangle avec le point de déplacement
    // Contrat :
    //

    virtual Rectangle* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Rectangle & operator = ( const Rectangle & unRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Paramètre :
    //  unRectangle : rectangle déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //  Constructeur par copie de la classe Rectangle
    // Contrat :
    //

    Rectangle ( string nom, int x1, int y1, int x2, int y2 );
    // Paramètres :
    //  nom : nom du rectangle
    //  x1 : coordonné x du point 1
    //  y1 : coordonné y du point 1
    //  x2 : coordonné x du point 2
    //  y2 : coordonné y du point 2
    // Mode d'emploi :
    //  Constructeur de la classe Rectangle
    // Contrat :
    //

    Rectangle ( string nom, Point p1, Point p2 );
    // Paramètres :
    //  nom : nom du rectangle
    //  p1 : point 1
    //  p2 : point 2
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Rectangle ( );
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
    Point p1;
    Point p2;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
