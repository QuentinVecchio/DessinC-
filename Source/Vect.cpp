/*************************************************************************
                          Vect -  description
                             -------------------
    début                : 12/01/16
    copyright            : (C) 2016 par Adrien, Quentin
*************************************************************************/

//---------- Réalisation de la classe <Vect> (fichier Vect.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>


//------------------------------------------------------ Include personnel
#include "Vect.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Vect::Print () const
// Algorithme :
//
{
	stringstream ss;
	ss <<  x << " " << y;
	string str = ss.str();
	return str;
} //----- Fin de Print

int Vect::ProdVect(const Vect & V1 , Vect & V2)
// Algorithme :
//
{
	return V1.x* V2.y - V1.y* V2.x;
}

int Vect::GetX () const
// Algorithme :
//
{
	return x;
} //----- Fin de GetX

void Vect::SetX (const int &x)
// Algorithme :
//
{
	this->x = x;
} //----- Fin de SetX

int Vect::GetY () const
// Algorithme :
//
{
	return y;
} //----- Fin de GetY
    
void Vect::SetY (const int &y)
// Algorithme :
//
{
	this->y = y;
} //----- Fin de SetY

//------------------------------------------------- Surcharge d'opérateurs
Vect & Vect::operator = ( const Vect & aVect )
// Algorithme :
//
{
	x = aVect.x;
	y = aVect.y;
	return *this;
} //----- Fin de operator =

Vect Vect::operator + ( const Vect & aVect ) const
// Algorithme :
//
{
	Vect p (x + aVect.x,y + aVect.y);
	return p;
} //----- Fin de operator +

Vect Vect::operator - ( const Vect & aVect ) const
// Algorithme :
//
{
	Vect p (x - aVect.x,y - aVect.y);
	return p;
} //----- Fin de operator -


Vect Vect::operator * ( const int lambda ) const
// Algorithme :
//
{
	int nx= x*lambda;
	int ny= y*lambda;
	Vect p (nx,ny);
	return p;
} //----- Fin de operator *

int Vect::operator * ( const Vect aVect ) const
// Algorithme :
//
{
	return x*aVect.x + y *aVect.y;
} //----- Fin de operator *

ostream& operator << (ostream &out, const Vect &unVect)
// Algorithme :
//
{
	out << unVect.Print();
	return out;
}//----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Vect::Vect ( const Vect & aVect )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Vect>" << endl;
#endif
    x = aVect.x;
    y = aVect.y;
} //----- Fin de Vect (constructeur de copie)


Vect::Vect ( int aX, int aY ):
		x(aX), y(aY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Vect>" << endl;
#endif
} //----- Fin de Vect


Vect::~Vect ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Vect>" << endl;
#endif
} //----- Fin de ~Vect


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
