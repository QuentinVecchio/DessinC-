/*************************************************************************
                           UndoRedo  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <UndoRedo> (fichier UndoRedo.h) ------
#if ! defined ( UndoRedo_H )
#define UndoRedo_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <stack>
#include "Command.h"
#include "Figure.h"
#include <map>
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <UndoRedo>
//  La classe UndoRedo permet le stockage des actions sur un programme
//  On peut de ce fait faire des Redo et des Undo
//------------------------------------------------------------------------ 

class UndoRedo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AddUndo(const Command &cmd);
    // Paramètre
    //  cmd : UndoRedo
    // Mode d'emploi :
    //  Méthode qui ajoute dans la pile Undo une UndoRedoe
    // Contrat :
    //

    void AddRedo(const Command &cmd);
    // Paramètre
    //  cmd : UndoRedo
    // Mode d'emploi :
    //  Méthode qui ajoute dans la pile Redo une UndoRedoe
    // Contrat :
    //

    string Undo();
    // Mode d'emploi :
    //  Méthode qui depile la pile Undo et retourne la UndoRedoe
    // Contrat :
    //

    string Redo();
    // Mode d'emploi :
    //  Méthode qui depile la pile Redo et retourne la UndoRedoe
    // Contrat :
    //

    unsigned int GetLimit() const;
    // Mode d'emploi :
    //  Méthode qui donne la limite dans la pile
    // Contrat :
    //

    void SetLimit(  const unsigned int limit );
    // Mode d'emploi :
    //  Méthode qui modifie la limite de la pile
    // Contrat :
    //

    UndoRedo* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
	UndoRedo & operator = ( const UndoRedo & unUndoRedo );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	UndoRedo ( const UndoRedo & unUndoRedo );
	//Paramètre
	//	unUndoRedo : UndoRedo déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //	
    // Contrat :
    //

    UndoRedo ( const unsigned int limit );
    // Mode d'emploi :
    //	Constructeur de la classe UndoRedo
    // Contrat :
    //

    virtual ~UndoRedo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    stack<Command> undo;
    stack<Command> redo;
    unsigned int limit;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <UndoRedo>

#endif // UndoRedo_H
