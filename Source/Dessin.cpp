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
	bool Dessin::AddByCmd( const string &donnees )
	// Algorithme :
	//
	{
		string *tabData = new string[100];
		int nElt = Parseur(donnees, ' ', tabData, 100);
		if(nElt >= 3)
		{	string type = tabData[0];
			string n = tabData[1];
			if(this->GetFigure(n) == NULL)
			{	if(type == "S" && nElt == 6)
				{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
					Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
					Segment *s = new Segment(n, p1, p2);
					this->Add(s);
				}
				else if(type == "R" && nElt == 6)
				{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
					Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
					Rectangle *r = new Rectangle(n, p1, p2);
					this->Add(r);
				} 
				else if(type == "PC")
				{

				}
				else if(type == "OR")
				{	Union *u = new Union(n);
					for(int i=2;i<nElt;i++)
					{	Figure *f = this->GetFigure(tabData[i]);
						if(f != NULL)
						{	u->Add(f->Copy());
						}
					}
					this->Add(u);
				}
				else if(type == "OI")
				{	Intersection *u = new Intersection(n);
					for(int i=2;i<nElt;i++)
					{	Figure *f = this->GetFigure(tabData[i]);
						if(f != NULL)
						{	u->Add(f->Copy());
						}
					}
					this->Add(u);
				}
				else if(type == "D")
				{	SetName(n);
				}
				else
				{	delete[] tabData;
					return false;
				}
				delete[] tabData;
				return true;
			}
		}
		delete[] tabData;
		return false;
	} //----- Fin de AddFigure

	string Dessin::Print() const
	// Algorithme :
	//
	{
		stringstream ss;
		ss << "D " << this->GetName() << " " << this->figures.size();
		ss << SetOfFigures::Print();
		string str = ss.str();
		return str;
	} //----- Fin de Print

	bool Dessin::IsInFigure( const string & name, const Vect &p ) const
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

	bool Dessin::IsIn( const Vect &p ) const
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

	void Dessin::MoveFigure( const string & name, const Vect &p )
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
        {	fichier << "D " << GetName() << " " << this->figures.size() << endl;
			for(map<string, Figure *> ::const_iterator mi = this->figures.begin(); mi != this->figures.end(); ++mi)
			{	if(mi->second != NULL)
				{	fichier << *(mi->second) << endl;
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
		string ligne;
		ifstream *fichier = new ifstream(link.c_str(), ios::in);
        if(*fichier)
        {	this->RemoveAll();
			while(getline(*fichier, ligne))
		    {	if(this->AddByLoad(ligne, this, fichier) == false)
		    	{	return false;
		    	}
		    }
            fichier->close();
            delete fichier;
            return true;
        }
		else
		{	 delete fichier;
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

	bool Dessin::AddByLoad( const string &donnees, SetOfFigures *conteneur, ifstream *fichier)
	// Algorithme :
	//
	{	
		string *tabData = new string[100];
		int nElt = Parseur(donnees, ' ', tabData, 100);
		if(nElt >= 3)
		{	string type = tabData[0];
			string n = tabData[1];
			if(conteneur->GetFigure(n) == NULL)
			{	if(type == "S" && nElt == 6)
				{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
					Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
					Segment *s = new Segment(n, p1, p2);
					conteneur->Add(s);
				}
				else if(type == "R" && nElt == 6)
				{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
					Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
					Rectangle *r = new Rectangle(n, p1, p2);
					conteneur->Add(r);
				} 
				else if(type == "PC")
				{

				}
				else if(type == "OR" || type == "OI")
				{	SetOfFigures *u = NULL;
					if(type == "OR")
					{	u = new Union(n);
					}
					else
					{	u = new Intersection(n);
					}
					int l = stoi(tabData[2].c_str());
					for(int i=0;i<l;i++)
					{	string cmd;
						if(getline(*fichier, cmd) == false)
						{	delete[] tabData;
							return false;
						}
						else
						{	if(this->AddByLoad(cmd, u,fichier) == false)
							{	delete[] tabData;
								return false;
							}
						}
					}
					this->Add(u);
				}
				else if(type == "D")
				{	SetName(n);
				}
				else
				{	delete[] tabData;
					return false;
				}
				delete[] tabData;
				return true;
			}
		}
		delete[] tabData;
		return false;
	} //----- Fin de Interprete
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
