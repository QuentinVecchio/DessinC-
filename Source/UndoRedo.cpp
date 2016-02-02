/*************************************************************************
                           UndoRedo  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <UndoRedo> (fichier UndoRedo.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "UndoRedo.h"
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
    void UndoRedo::AddUndo(const Command &cmd)
    // Algorithme :
	//
	{
		undo.push(cmd);
	} //----- Fin de AddUndo

    void UndoRedo::AddRedo(const Command &cmd)
    // Algorithme :
	//
	{	redo.push(cmd);
	} //----- Fin de AddRedo

    string UndoRedo::Undo()
    // Algorithme :
	//
	{
		if(undo.empty() == false) 
		{	string c = undo.top().GetUnExecute();
			redo.push(undo.top());
			undo.pop();
			return c;
		} 
		else 
		{	return "";
		}
	} //----- Fin de Undo

    string UndoRedo::Redo()
    // Algorithme :
	//
	{
		if(redo.empty() == false) 
		{	string c = redo.top().GetExecute();
			undo.push(redo.top());
			redo.pop();
			return c;
		} 
		else 
		{	return "";
		}
	} //----- Fin de Redo

    UndoRedo* UndoRedo::Copy( ) const
    // Algorithme :
	//
	{
		UndoRedo *c = new UndoRedo(*this);
		return c;
	} //----- Fin de Copy

//------------------------------------------------- Surcharge d'opérateurs
	UndoRedo & UndoRedo::operator = ( const UndoRedo & unUndoRedo )
	// Algorithme :
	//
	{
		undo = unUndoRedo.undo;
		redo = unUndoRedo.redo;
		return *this;
	} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
	UndoRedo::UndoRedo ( const UndoRedo & unUndoRedo )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <UndoRedo>" << endl;
	#endif
		undo = unUndoRedo.undo;
		redo = unUndoRedo.redo;
	} //----- Fin de UndoRedo (constructeur de copie)


	UndoRedo::UndoRedo ()
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <UndoRedo>" << endl;
	#endif
	} //----- Fin de UndoRedo


	UndoRedo::~UndoRedo ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <UndoRedo>" << endl;
	#endif
	} //----- Fin de ~UndoRedo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
