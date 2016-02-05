/*************************************************************************
                           main.cpp  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include "../../Source/Dessin.h"
#include "../../Source/Fonctions.h"
#include "../../Source/UndoRedo.h"
using namespace std;
//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//------------------------------------------------------------- Prototypes

//---------------------------------------------------------- Fonction main

int main()
{
	string commande = "";
	Dessin *d = new Dessin("Dessin");
	UndoRedo *pile = new UndoRedo(20);
	map<string,Figure*> *exclu = new map<string,Figure*>();
	map<string,Dessin*> *dessinExclu = new map<string,Dessin*>();
	bool stop = false;
	do
	{	cin.tie(0);
		if(getline(cin,commande))
		{	stop = interpreteCommande(commande, &d, pile, exclu, dessinExclu, false);
		}
		else
		{	stop = true;
		}
	}while(stop == false);
	for(map<string, Figure *>::iterator mi = exclu->begin(); mi != exclu->end(); ++mi)
	{	if(mi->second != NULL)
		{	delete mi->second;	
		}		
	}
	for(map<string, Dessin *>::iterator mi = dessinExclu->begin(); mi != dessinExclu->end(); ++mi)
	{	if(mi->second != NULL)
		{	delete mi->second;	
		}		
	}
	delete exclu;
	delete dessinExclu;
	delete pile;
	delete d;
	return 0;
}
