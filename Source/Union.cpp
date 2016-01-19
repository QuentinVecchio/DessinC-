/*************************************************************************
                           Union  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <Union> (fichier Union.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Union.h"
#include "Fonctions.h"
#include <fstream>
#include <sstream>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
	string Union::Print() const
	// Algorithme :
	//
	{
		stringstream ss;
		ss << "OR " << this->GetName() << " " << this->figures.size();
		ss << SetOfFigures::Print();
		string str = ss.str();
		return str;
	} //----- Fin de Print

	bool Union::IsIn( const Vect &p ) const
	// Algorithme :
	//
	{
		for(map<string, Figure *> ::const_iterator mi = this->figures.begin(); mi != this->figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	if(mi->second->IsIn(p))
					return true; 
			}		
		}
		return false;
	} //----- Fin de IsIn

	Union* Union::Copy( ) const
	// Algorithme :
	//
	{
		Union * u = new Union(*this);
		return u;
	} //----- Fin de Copy

//------------------------------------------------- Surcharge d'opérateurs
	Union & Union::operator = ( const Union & unUnion )
	// Algorithme :
	//
	{
		this->SetName(unUnion.GetName());
		for(map<string, Figure *>::iterator mi = unUnion.GetFigures().begin(); mi != unUnion.GetFigures().end(); ++mi)
		{	if(mi->second != NULL)
			{	figures[mi->first] = mi->second->Copy();
			}	
		}
		return *this;
	} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
	Union::Union ( const Union & unUnion ) : SetOfFigures(unUnion)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Union>" << endl;
	#endif
	} //----- Fin de Union (constructeur de copie)


	Union::Union ( const string &name ) : SetOfFigures(name)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Union>" << endl;
	#endif
	} //----- Fin de Union


	Union::~Union ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Union>" << endl;
	#endif
	} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
