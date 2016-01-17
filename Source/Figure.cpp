/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <Figure> (fichier Figure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

	string Figure::GetName() const
	// Algorithme :
	//
	{
		return name;
	} //----- Fin de GetName

	void Figure::SetName( const string &s )
	// Algorithme :
	//
	{
		name = s;
	} //----- Fin de SetName

	string Figure::Print() const
	// Algorithme :
	//
	{
		string print = "F " + name;
		return print;
	} //----- Fin de Print

//------------------------------------------------- Surcharge d'opérateurs
	ostream& operator<<( ostream& out, const Figure &f )
	// Algorithme :
	//
	{
		out << f.Print();
		return out;
	}//----- Fin de operator << 

//-------------------------------------------- Constructeurs - destructeur
	Figure::Figure ( const Figure & unFigure )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Figure>" << endl;
	#endif
	} //----- Fin de Figure (constructeur de copie)


	Figure::Figure ( const string &n )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Figure>" << endl;
	#endif
		name = n;
	} //----- Fin de Figure


	Figure::~Figure ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Figure>" << endl;
	#endif
	} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
