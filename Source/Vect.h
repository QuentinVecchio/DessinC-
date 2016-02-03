/*************************************************************************
                          Vect -  description
                             -------------------
    début                : 12/01/16
    copyright            : (C) 2016 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------- Interface de la classe Vect(fichier Vect.h) ------
#if ! defined ( Vect_H )
#define Vect_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Vect.h
//  Cette classe permet l'implémentation d'un Vect de coordonné entière
//
//------------------------------------------------------------------------

class Vect
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string Print () const;
    // Mode d'emploi :
    //  
    // Contrat :
    //

    static int ProdVect(const Vect & V1 , Vect & V2);
    // Mode d'emploi :
    // retourne le produit vectoriel de V1 V2;
    // Contrat :
    //

    int GetX () const;
    // Mode d'emploi :
    //  
    // Contrat :
    //

    void SetX (const int &x);
    // Mode d'emploi :
    //  
    // Contrat :
    //

    int GetY () const;
    // Mode d'emploi :
    //  
    // Contrat :
    //

    void SetY (const int &y);
    // Mode d'emploi :
    //  
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Vect & operator = ( const Vect & unVect );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Vect operator + ( const Vect & aVect ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Vect operator - ( const Vect & aVect ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Vect operator * ( const int lambda ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int operator * ( const Vect lambda ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream& operator << (ostream &out, const Vect &unVect);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Vect ( const Vect & Vect );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Vect (int ax, int ay );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Vect ( );
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

//----------------------------------------- Types dépendants de <Vect>

#endif // Vect_H
