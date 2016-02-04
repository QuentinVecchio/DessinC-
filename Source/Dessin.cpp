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
#include "Command.h"
#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
    
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
				{	try 
					{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
						Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
						Segment *s = new Segment(n, p1, p2);
						this->Add(s);
					}
					catch(invalid_argument& e)
					{	cout << "# Erreur parametre dans segment" << endl;
						return false;
					}					
				}
				else if(type == "R" && nElt == 6)
				{	try 
					{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
						Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
						Rectangle *r = new Rectangle(n, p1, p2);
						this->Add(r);
					}
					catch(invalid_argument& e)
					{	cout << "# Erreur parametre dans rectangle" << endl;
						return false;
					}	
				} 
				else if(type == "PC")
				{	Polygon *p = new Polygon(n);
					for(int i=2;i<nElt;i+=2)
					{	try 
						{	Vect point(stoi(tabData[i].c_str()), stoi(tabData[i+1].c_str()));
							p->Add(point);
						}
						catch(std::invalid_argument& e)
						{	cout << "# Erreur parametre dans polygone" << endl;
							return false;
						}	
					}
					if(p->IsConvexe())
						this->Add(p);
					else
					{
						cout << "# Erreur polygone non convexe" << endl;
						return false;
					}
				}
				else if(type == "OR")
				{	Union *u = new Union(n);
					for(int i=2;i<nElt;i++)
					{	Figure *f = this->GetFigure(tabData[i]);
						if(f != NULL)
						{	u->Add(f->Copy());
						}
						else
						{	cout << "# Attention figure " + tabData[i] + " n'existe pas donc non ajoutee" << endl;
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
						else
						{	cout << "# Attention figure " + tabData[i] + " n'existe pas donc non ajoutee" << endl;
						}
					}
					this->Add(u);
				}
				else if(type == "D")
				{	SetName(n);
				}
				else
				{	delete[] tabData;
					cout << "# Erreur format inconnu" << endl;
					return false;
				}
				delete[] tabData;
				return true;
			}
		}
		delete[] tabData;
		cout << "# Erreur format inconnu" << endl;
		return false;
	} //----- Fin de AddFigure

	string Dessin::Print() const
	// Algorithme :
	//
	{
		stringstream ss;
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
		{	cout << "# Erreur la figure n'existe pas" << endl;
			return false;
		}
	} //----- Fin de IsIn

	bool Dessin::IsIn( const Vect &p ) const
	// Algorithme :
	//
	{
		for(map<string, Figure *> ::const_iterator mi = this->figures.begin(); mi != this->figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	if(mi->second->IsIn(p))
				{	return true; 
				}
			}		
		}
		return false;
	} //----- Fin de IsIn

	bool Dessin::MoveFigure( const string & name, const Vect &p )
	// Algorithme :
	//
	{
		Figure *f = this->GetFigure(name);
		if(f != NULL)
		{	f->Move(p);
			return true;
		}
		else
		{	cout << "# Erreur la figure n'existe pas" << endl;
			return false;
		}
	} //----- Fin de MoveFigure

	bool Dessin::Remove(const string &name)
	{
		if(this->GetFigure(name) != NULL)
		{	delete figures[name];
			figures.erase(name);
			return true; 
		}
		else
		{	cout << "# Erreur la figure n'existe pas" << endl;
			return false;
		}
	}

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
		{	cout << "# Erreur ouverture fichier " << link << endl;
			return false;
		}
	} //----- Fin de Save

	bool Dessin::Load(const string &link)
	// Algorithme :
	//
	{
		string ligne;
		fstream fichier(link.c_str());
        if(fichier)
        {	this->RemoveAll();
			while(getline(fichier, ligne))
		    {	if(this->AddByLoad(ligne, this, &fichier) == false)
		    	{	return false;
		    	}
		    }
            fichier.close();
            return true;
        }
		else
		{	cout << "# Erreur ouverture fichier " << link << endl;
			return false;
		}
	} //----- Fin de Load

	Dessin* Dessin::Copy( ) const
	// Algorithme :
	//
	{
		Dessin * d = new Dessin(*this);
		return d;
	} //----- Fin de Copy

	bool Dessin::AddByLoad( const string &donnees, SetOfFigures *conteneur, fstream *fichier)
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
				{	try 
					{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
						Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
						Segment *s = new Segment(n, p1, p2);
						conteneur->Add(s);
					}
					catch(std::invalid_argument& e)
					{	cout << "# Erreur parametre dans segment" << endl;
						return false;
					}	
				}
				else if(type == "R" && nElt == 6)
				{	try 
					{	Vect p1(stoi(tabData[2].c_str()), stoi(tabData[3].c_str()));
						Vect p2(stoi(tabData[4].c_str()), stoi(tabData[5].c_str()));
						Rectangle *r = new Rectangle(n, p1, p2);
						conteneur->Add(r);
					}
					catch(std::invalid_argument& e)
					{	cout << "# Erreur parametre dans rectangle" << endl;
						return false;
					}
				} 
				else if(type == "PC")
				{
					Polygon *p = new Polygon(n);
					for(int i=2;i<nElt;i+=2)
					{	try 
						{	Vect point(stoi(tabData[i].c_str()), stoi(tabData[i+1].c_str()));
							p->Add(point);
						}
						catch(std::invalid_argument& e)
						{	cout << "# Erreur parametre dans polygone" << endl;
							return false;
						}
					}
					if(p->IsConvexe())
						this->Add(p);
					else
					{	cout << "# Erreur polygone non convexe" << endl;
						return false;
					}
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
						if(!getline(*fichier, cmd))
						{	delete[] tabData;
							return false;
						}
						else
						{	if(this->AddByLoad(cmd, u,fichier) == false)
							{	delete[] tabData;
								cout << "# Attention figure " + tabData[i] + " n'existe pas donc non ajoutee" << endl;
								return false;
							}
						}
					}
					conteneur->Add(u);
				}
				else if(type == "D" && nElt == 3)
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
		cout << "#	Fichier mal formé" << endl;
		return false;
	} //----- Fin de AddByLoad

//------------------------------------------------- Surcharge d'opérateurs
	Dessin & Dessin::operator = ( const Dessin & unDessin )
	// Algorithme :
	//
	{
		this->SetName(unDessin.GetName());
		for(map<string, Figure *>::iterator mi = unDessin.GetFigures().begin(); mi != unDessin.GetFigures().end(); ++mi)
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
