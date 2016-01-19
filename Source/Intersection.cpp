/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <Intersection> (fichier Intersection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Intersection.h"
#include "Fonctions.h"
#include <fstream>
#include <sstream>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
	string Intersection::Print() const
	// Algorithme :
	//
	{
		stringstream ss;
		ss << "OI " << this->GetName() << " " << this->figures.size();
		ss << SetOfFigures::Print();
		string str = ss.str();
		return str;
	} //----- Fin de Print

	bool Intersection::IsIn( const Point &p ) const
	// Algorithme :
	//
	{
		for(map<string, Figure *> ::const_iterator mi = this->figures.begin(); mi != this->figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	if(mi->second->IsIn(p) == false)
					return false; 
			}		
		}
		return true;
	} //----- Fin de IsIn

	Intersection* Intersection::Copy( ) const
	// Algorithme :
	//
	{
		Intersection * u = new Intersection(*this);
		return u;
	} //----- Fin de Copy

//------------------------------------------------- Surcharge d'opérateurs
	Intersection & Intersection::operator = ( const Intersection & unIntersection )
	// Algorithme :
	//
	{
		this->SetName(unIntersection.GetName());
		for(map<string, Figure *>::iterator mi = unIntersection.GetFigures().begin(); mi != unIntersection.GetFigures().end(); ++mi)
		{	if(mi->second != NULL)
			{	figures[mi->first] = mi->second->Copy();
			}	
		}
		return *this;
	} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
	Intersection::Intersection ( const Intersection & unIntersection ) : SetOfFigures(unIntersection)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Intersection>" << endl;
	#endif
	} //----- Fin de Intersection (constructeur de copie)


	Intersection::Intersection ( const string &name ) : SetOfFigures(name)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Intersection>" << endl;
	#endif
	} //----- Fin de Intersection


	Intersection::~Intersection ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Intersection>" << endl;
	#endif
	} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
