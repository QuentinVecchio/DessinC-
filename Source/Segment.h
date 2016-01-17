/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier Segment.h) ------
#if ! defined ( Segment_H )
#define Segment_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Point.h"
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

    virtual Segment* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Segment & operator = ( const Segment & unSegment );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Segment ( string nom, int x1, int y1, int x2, int y2 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Segment (string nom, Point p1, Point p2);
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
    Point p1;
    Point p2;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Segment>

#endif // XXX_H
