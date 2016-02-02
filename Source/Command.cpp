/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <Command> (fichier Command.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Command.h"
#include "Fonctions.h"
#include "Rectangle.h"
#include "Segment.h"
#include "Union.h"
#include "Intersection.h"
#include "Fonctions.h"
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
    string Command::GetExecute() const
    // Algorithme :
	//
	{
		return execute;
	} //----- Fin de GetExecute

    string Command::GetUnExecute() const
    // Algorithme :
	//
	{
		return unexecute;
	} //----- Fin de GetUnExecute

	void Command::SetExecute(const string & s)
    // Algorithme :
	//
	{
		execute = s;
	} //----- Fin de GetUnExecute


    void Command::SetUnExecute(const string & s)
    // Algorithme :
	//
	{
		unexecute = s;
	} //----- Fin de GetUnExecute


    Command* Command::Copy( ) const
    // Algorithme :
	//
	{
		Command *c = new Command(*this);
		return c;
	} //----- Fin de Copy

//------------------------------------------------- Surcharge d'opérateurs
	Command & Command::operator = ( const Command & unCommand )
	// Algorithme :
	//
	{
		execute = unCommand.execute;
		unexecute = unCommand.unexecute;
		return *this;
	} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
	Command::Command ( const Command & unCommand )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Command>" << endl;
	#endif
		execute = unCommand.execute;
		unexecute = unCommand.unexecute;
	} //----- Fin de Command (constructeur de copie)


	Command::Command (const string & ex, const string & un)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Command>" << endl;
	#endif
		execute = ex;
		unexecute = un;
	} //----- Fin de Command


	Command::~Command ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Command>" << endl;
	#endif
	} //----- Fin de ~Command


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
