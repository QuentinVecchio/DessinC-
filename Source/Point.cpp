/*************************************************************************
                          Point -  description
                             -------------------
    début                : 12/01/16
    copyright            : (C) 2016 par Adrien, Quentin
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>


//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Point::Print () const
// Algorithme :
//
{
	stringstream ss;
	ss <<  x << " " << y;
	string str = ss.str();
	return str;
} //----- Fin de Print

int Point::GetX () const
// Algorithme :
//
{
	return x;
} //----- Fin de GetX

void Point::SetX (const int &x)
// Algorithme :
//
{
	this->x = x;
} //----- Fin de SetX

int Point::GetY () const
// Algorithme :
//
{
	return y;
} //----- Fin de GetY
    
void Point::SetY (const int &y)
// Algorithme :
//
{
	this->y = y;
} //----- Fin de SetY

//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & aPoint )
// Algorithme :
//
{
	x = aPoint.x;
	y = aPoint.y;
	return *this;
} //----- Fin de operator =

Point Point::operator + ( const Point & aPoint ) const
// Algorithme :
//
{
	Point p (x + aPoint.x,y + aPoint.y);
	return p;
} //----- Fin de operator +


Point Point::operator * ( const int lambda ) const
// Algorithme :
//
{
	int nx= x*lambda;
	int ny= y*lambda;
	Point p (nx,ny);
	return p;
} //----- Fin de operator *

ostream& operator << (ostream &out, const Point &unPoint)
// Algorithme :
//
{
	out << unPoint.Print();
	return out;
}//----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & aPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
    x = aPoint.x;
    y = aPoint.y;
} //----- Fin de Point (constructeur de copie)


Point::Point ( int aX, int aY ):
		x(aX), y(aY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
