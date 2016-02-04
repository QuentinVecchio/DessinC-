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
		if(undo.size() < limit)
		{	undo.push(cmd);
		}
		else
		{	stack<Command> pile;
			pile.push(cmd);
			while(undo.empty() == false)
			{	pile.push(undo.top());
				undo.pop();
			}	
			pile.pop();
			while(pile.empty() == false)
			{	undo.push(pile.top());
				pile.pop();
			}
		}

	} //----- Fin de AddUndo

    void UndoRedo::AddRedo(const Command &cmd)
    // Algorithme :
	//
	{	if(redo.size() <= limit)
		{	redo.push(cmd);
		}
		else
		{	stack<Command> pile;
			pile.push(cmd);
			while(redo.empty() == false)
			{	pile.push(redo.top());
				redo.pop();
			}	
			pile.pop();
			while(pile.empty() == false)
			{	redo.push(pile.top());
				pile.pop();
			}
		}
	} //----- Fin de AddRedo

    string UndoRedo::Undo()
    // Algorithme :
	//
	{
		if(undo.empty() == false) 
		{	string c = undo.top().GetUnExecute();
			AddRedo(undo.top());
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
			AddUndo(redo.top());
			redo.pop();
			return c;
		} 
		else 
		{	return "";
		}
	} //----- Fin de Redo

	unsigned int UndoRedo::GetLimit() const
    // Algorithme :
	//
	{
		return limit;
	} //----- Fin de GetLimit

    void UndoRedo::SetLimit(const unsigned int limit)
    // Algorithme :
	//
	{
		this->limit = limit;
	} //----- Fin de SetLimit

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
		limit = unUndoRedo.limit;
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
		limit = unUndoRedo.limit;
	} //----- Fin de UndoRedo (constructeur de copie)


	UndoRedo::UndoRedo ( const unsigned int limit )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <UndoRedo>" << endl;
	#endif
		this->limit = limit;
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
