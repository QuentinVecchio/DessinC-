/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 16/01/2016
    copyright            : (C) 2016 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cmath>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int Rectangle::GetWeight() const
// Algorithme :
//
{
	return (p2.GetX() - p1.GetX());
} //----- Fin de GetWeight

int Rectangle::GetLength() const
// Algorithme :
//
{
	return (p1.GetY() - p2.GetY());
} //----- Fin de GetLength

Vect Rectangle::GetP1() const
// Algorithme :
//
{
	return p1;
} //----- Fin de GetP1

void Rectangle::SetP1( const Vect &p )
// Algorithme :
//
{
	this->p1 = p;
} //----- Fin de SetP1

Vect Rectangle::GetP2() const
// Algorithme :
//
{
	return p2;
} //----- Fin de GetP2

void Rectangle::SetP2( const Vect &p )
// Algorithme :
//
{
	this->p2 = p2;
} //----- Fin de SetP2

string Rectangle::Print() const
// Algorithme :
//
{
	stringstream ss;
	ss << "R " <<  this->GetName() << " " << p1 << " " << p2;
	string str = ss.str();
	return str;
} //----- Fin de Print

Rectangle* Rectangle::Copy( ) const
// Algorithme :
//
{
	Rectangle *r = new Rectangle(*this);
	return r;
} //----- Fin de Copy


bool Rectangle::IsIn( const Vect &Vect ) const
// Algorithme :
//
{
	return (Vect.GetX() >= p1.GetX() && Vect.GetX() <= p2.GetX()) && (Vect.GetY() <= p1.GetY() && Vect.GetY() >= p2.GetY());
} //----- Fin de IsIn

void Rectangle::Move( const Vect &Vect )
// Algorithme :
//
{
	p1 = p1 + Vect;
	p2 = p2 + Vect;
} //----- Fin de Move

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & Rectangle::operator = ( const Rectangle & unRectangle )
// Algorithme :
//
{
	p1 = Vect(unRectangle.p1);
	p2 = Vect(unRectangle.p2);
	this->SetName(unRectangle.GetName());
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ) : Figure(unRectangle.GetName()), p1(unRectangle.p1.GetX(), unRectangle.p1.GetY()), p2(unRectangle.p2.GetX(), unRectangle.p2.GetY()) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( string nom, int x1, int y1, int x2, int y2 ) : Figure(nom), p1(x1,y1), p2(x2,y2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle ( string nom, Vect p1, Vect p2 ) : Figure(nom), p1(p1), p2(p2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
