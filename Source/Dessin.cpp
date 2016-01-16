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
#include <fstream>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

	map<string, Figure*> Dessin::GetFigures() const
	// Algorithme :
	//
	{
		return figures;
	} //----- Fin de GetFigures

	void Dessin::SetFigures( const map<string, Figure *> &figures )
	// Algorithme :
	//
	{
		this->figures = figures;
	} //----- Fin de SetFigures

	Figure * Dessin::GetFigure( const string &n ) const
	// Algorithme :
	//
	{
		Figure *f = figures.find(n);
		if(f != figures.end())
		{	return f->second();
		}
		else
		{	return NULL;
		}
	} //----- Fin de GetFigure

	bool Dessin::AddFigure( const string &donnees )
	// Algorithme :
	//
	{
		if(this->GetFigure(n) != NULL)
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
		{	return false;
		}
	} //----- Fin de AddFigure

	bool Dessin::DeleteFigure( const string &n )
	// Algorithme :
	//
	{
		if(this->GetFigure(n) != NULL)
		{	figures.erase(n);
		}
		else
		{	return false;
		}
	} //----- Fin de DeleteFigure

	string Dessin::Print() const
	// Algorithme :
	//
	{
		string p = "";
		for(figures::const_iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second() != NULL)
			{	p += mi->second()->Print() + "\n";
			}		
		}
		return p;
	} //----- Fin de Print

	void Dessin::Move( const string & name, const Point &p)
	// Algorithme :
	//
	{
		Figure *f = this->GetFigure(name);
		if(f != NULL)
		{	return f->Move(p);
		}
		else
		{	return false;
		}
	} //----- Fin de Move

	bool Dessin::IsIn( const string & name, const Point &p ) const
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

	bool Dessin::Save(const string &link)
	// Algorithme :
	//
	{
		ofstream fichier(link, ios::out);
        if(fichier)
        {
			for(figures::const_iterator mi = figures.begin(); mi != figures.end(); ++mi)
			{	if(mi->second() != NULL)
				{	fichier << mi->second() << endl;
				}		
			}
        }
		else
		{
			return false;
		}
	} //----- Fin de Save

	void Dessin::Load(const string &link)
	// Algorithme :
	//
	{
		ifstream fichier(link, ios::in);
        if(fichier)
        {
			figures.clear();
			string ligne;
			while(getline(fichier, ligne))
		    {	this->AddFigure(ligne);
		    }
            fichier.close();
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

//------------------------------------------------- Surcharge d'opérateurs
	Dessin & Dessin::operator = ( const Dessin & unDessin )
	// Algorithme :
	//
	{
		this->figures = unDessin.figures;
		return *this;
	} //----- Fin de operator =

	ostream& operator<<( ostream& out, const Dessin &d )
	// Algorithme :
	//
	{
		out << d.Print() << endl;
		return out;
	} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
	Dessin::Dessin ( const Dessin & unDessin )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Dessin>" << endl;
	#endif
		this->figures = unDessin.figures;
	} //----- Fin de Dessin (constructeur de copie)


	Dessin::Dessin ( )
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
		for(figures::const_iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second() != NULL)
			{	delete mi->second();
				p += mi->second()->Print();
			}		
		}
		figures.clear();
	} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
