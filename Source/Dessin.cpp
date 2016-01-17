/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <Dessin> (fichier Dessin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Dessin.h"
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
	bool Dessin::AddByCmd( const string &donnees )
	// Algorithme :
	//
	{
		/*if(this->GetFigure(n) != NULL)
		{
			if(type == "R")
			{	string name = "";
				string *tabData = new string[100];
				int nElt = Parseur(donnees, ' ', tabData, 100);
				if(nElt != 6)
				{	int x1 = stoi(tabData[2]), y1 = stoi(tabData[3]), x2 = stoi(tabData[4]), y2 = stoi(tabData[5]);
					name = tabData[1];
					Rectangle *r = new Rectangle(name, x1, y1, x2, y2);
					figures[name] = r;
				}
				else
				{	return false;
				}
			}
			else if(type == "S")
			{	string name = "";
				string *tabData = new string[100];
				int nElt = Parseur(donnees, ' ', tabData, 100);
				if(nElt != 6)
				{	int x1 = stoi(tabData[2]), y1 = stoi(tabData[3]), x2 = stoi(tabData[4]), y2 = stoi(tabData[5]);
					name = tabData[1];
					Segment *s = new Segment(name, x1, y1, x2, y2);
					figures[name] = s;
				}
				else
				{	return false;
				}	
			}
			else if(type == "PC")
			{	
			}
			else
			{	return false;
			}
			return true;
		}
		else
		{	*/return false;
		//}
	} //----- Fin de AddFigure

	string Dessin::Print() const
	// Algorithme :
	//
	{
		stringstream ss;
		ss << "D " << this->GetName() << " " << this->figures.size() << endl;
		ss << SetOfFigures::Print();
		string str = ss.str();
		return str;
	} //----- Fin de Print

	bool Dessin::IsInFigure( const string & name, const Point &p ) const
	// Algorithme :
	//
	{
		Figure *f = this->GetFigure(name);
		if(f != NULL)
		{	return f->IsIn(p);
		}
		else
		{	return false;
		}
	} //----- Fin de IsIn

	bool Dessin::IsIn( const Point &p ) const
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

	void Dessin::MoveFigure( const string & name, const Point &p )
	// Algorithme :
	//
	{
		Figure *f = this->GetFigure(name);
		if(f != NULL)
		{	f->Move(p);
		}
	} //----- Fin de MoveFigure

	bool Dessin::Save(const string &link)
	// Algorithme :
	//
	{
		ofstream fichier(link.c_str(), ios::out);
        if(fichier)
        {
			for(map<string, Figure *> ::const_iterator mi = this->figures.begin(); mi != this->figures.end(); ++mi)
			{	if(mi->second != NULL)
				{	fichier << mi->second << endl;
				}		
			}
			return true;
        }
		else
		{
			return false;
		}
	} //----- Fin de Save

	bool Dessin::Load(const string &link)
	// Algorithme :
	//
	{
		ifstream fichier(link.c_str(), ios::in);
        if(fichier)
        {
			this->RemoveAll();
			string ligne;
			while(getline(fichier, ligne))
		    {	this->AddByCmd(ligne);
		    }
            fichier.close();
            return true;
        }
		else
		{
			return false;
		}
	} //----- Fin de Load

	void Dessin::Undo()
	// Algorithme :
	//
	{
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	} //----- Fin de Undo

	void Dessin::Redo()
	// Algorithme :
	//
	{
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	} //----- Fin de Redo

	Dessin* Dessin::Copy( ) const
	// Algorithme :
	//
	{
		Dessin * d = new Dessin(*this);
		return d;
	} //----- Fin de Copy

//------------------------------------------------- Surcharge d'opérateurs
	Dessin & Dessin::operator = ( const Dessin & unDessin )
	// Algorithme :
	//
	{
		this->SetName(unDessin.GetName());
		map<string, Figure *> ens = unDessin.GetFigures();
		for(map<string, Figure *>::iterator mi = ens.begin(); mi != ens.end(); ++mi)
		{	if(mi->second != NULL)
			{	figures[mi->first] = mi->second->Copy();
			}	
		}
		return *this;
	} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
	Dessin::Dessin ( const Dessin & unDessin ) : SetOfFigures(unDessin)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Dessin>" << endl;
	#endif
	} //----- Fin de Dessin (constructeur de copie)


	Dessin::Dessin ( const string &name ) : SetOfFigures(name)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <Dessin>" << endl;
	#endif
	} //----- Fin de Dessin


	Dessin::~Dessin ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <Dessin>" << endl;
	#endif
	} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
