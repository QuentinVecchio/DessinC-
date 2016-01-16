/*************************************************************************
                          Point -  description
                             -------------------
    début                : 12/01/16
    copyright            : (C) 2016 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------- Interface de la classe Point(fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Point.h
//  Cette classe permet l'implémentation d'un point de coordonné entière
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string Print () const;
    // Mode d'emploi :
    //  
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point operator + ( const Point & aPoint ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point operator * ( const int lambda ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream& operator << (ostream &out, const Point &unPoint);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & Point );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point (int ax, int ay );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
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
    int x;
    int y;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
