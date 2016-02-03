/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "Segment.h"
//#include "Vect.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

string Segment::Print() const
// Algorithme :
//
{
	string sp1 = p1.Print();
	string sp2 = p2.Print();

	return "S " + this->GetName() + " " + sp1 + " " + sp2;
} //----- Fin de operator Print


bool Segment::IsIn( const Vect &p ) const
// Algorithme :
//
{
	Vect vectorSeg = p1-p2;
	Vect vectorVect = p1-p;
	bool isColinear = (vectorSeg.GetX()/vectorVect.GetX() == vectorSeg.GetY()/vectorVect.GetY()); // le Vect est il sur la droit support du segement

	bool dimantionRight  = (vectorSeg.GetX() < vectorVect.GetX()& vectorVect.GetX()<0) // l'absice du est il comprie entre les absices des estrémitéer du segement
			||      (vectorSeg.GetX() > vectorVect.GetX()& vectorVect.GetX()>0);


	return isColinear && dimantionRight;

} //----- Fin de operator IsIn

void Segment::Move( const Vect &dp )
// Algorithme :
//
{
	p1=p1+dp;
	p2= p2+dp;
} //----- Fin de operator Move

Segment* Segment::Copy( ) const
// Algorithme :
//
{
	Segment *s = new Segment(*this);
	return s;
} //----- Fin de Copy

Vect Segment::GetP1( ) const
// Algorithme :
//
{
	return p1;
} //----- Fin de GetP1

Vect Segment::GetP2( ) const
// Algorithme :
//
{
	return p2;
} //----- Fin de GetP2

void Segment::SetP1(  const Vect &v )
// Algorithme :
//
{
	p1 = v;
} //----- Fin de SetP1

void Segment::SetP2( const Vect &v )
// Algorithme :
//
{
	p2 = v;
} //----- Fin de SetP2

float Segment::GetLength( ) const
// Algorithme :
//
{
	return 0;
} //----- Fin de GetLength

//------------------------------------------------- Surcharge d'opérateurs
Segment & Segment::operator = ( const Segment & aSegment )
// Algorithme :
//
{
    p1=aSegment.p1;
    p2=aSegment.p2;
    SetName(aSegment.GetName());
	return (*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & aSegment):
		Figure(aSegment.GetName()), p1(aSegment.p1),p2(aSegment.p2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif


} //----- Fin de Segment (constructeur de copie)


Segment::Segment( string nom, int x1, int y1, int x2, int y2 ):
		Figure(nom),p1(x1,x2),p2(x1,x2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif

} //----- Fin de Segment

Segment::Segment( string nom, Vect Vect1 , Vect Vect2):
		Figure(nom),p1(Vect1), p2(Vect2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif
} //----- Fin de Segment


Segment::~Segment ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Segment>" << endl;
#endif
} //----- Fin de ~Segment


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
