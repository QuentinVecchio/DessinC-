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
#include "Dessin.h"
#include "Fonctions.h"

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
	Dessin d("Dessin");
	bool stop = false;
	do
	{	cin.tie(0);
		if(getline(cin,commande))
		{	stop = interpretreCommande(commande, d);
		}
		else
		{	stop = true;
		}
	}while(stop == false);

	return 0;
}
