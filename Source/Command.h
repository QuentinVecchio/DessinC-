/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( Command_H )
#define Command_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Command>
//  La classe Command permet le stockage des actions sur un programme
//  On peut de ce fait faire des Redo et des Undo
//------------------------------------------------------------------------ 

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetExecute() const;
    // Mode d'emploi :
    //  Méthode qui renvoie la commande execute
    // Contrat :
    //

    string GetUnExecute() const;
    // Mode d'emploi :
    //  Méthode qui renvoie la commande unExecute
    // Contrat :
    //

    void SetExecute(const string & s);
    // Mode d'emploi :
    //  Méthode qui modifie la commande execute
    // Contrat :
    //

    void SetUnExecute(const string & s);
    // Mode d'emploi :
    //  Méthode qui modifie la commande unExecute
    // Contrat :
    //

    Command* Copy( ) const;
    // Mode d'emploi :
    //  Renvoie une nouvelle copie de l'objet
    //  Méthode virtuel 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
	Command & operator = ( const Command & unCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	Command ( const Command & unCommand );
	//Paramètre
	//	unCommand : Command déjà initialisé
    // Mode d'emploi (constructeur de copie) :
    //	
    // Contrat :
    //

    Command ( const string &execute, const string &unexecute);
    // Mode d'emploi :
    //	Constructeur de la classe Command
    // Contrat :
    //

    virtual ~Command ( );
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
    string execute;
    string unexecute;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Command>

#endif // Command_H
