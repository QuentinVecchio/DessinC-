/*************************************************************************
                           SetOfFigures  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//---------- Réalisation de la classe <SetOfFigures> (fichier SetOfFigures.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "SetOfFigures.h"
#include "Rectangle.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

	map<string, Figure *> SetOfFigures::GetFigures() const
	/// Algorithme :
	//
	{
		return figures;
	}//----- Fin de la méthode GetFigures

	void SetOfFigures::SetFigures( const map<string, Figure *> &ens )
	/// Algorithme :
	//
	{
		figures = ens;
	}//----- Fin de la méthode SetFigures

    bool SetOfFigures::Add(Figure *f)
    /// Algorithme :
	//
	{
		if(this->GetFigure(f->GetName()) == NULL)
		{	figures[f->GetName()] = f;
			return true;
		}
		else
		{	return false;
		}
	}//----- Fin de la méthode Add

    bool SetOfFigures::Remove(const string &n)
    // Algorithme :
	//
	{
		if(this->GetFigure(n) != NULL)
		{	delete figures[n];
			figures.erase(n);
			return true; 
		}
		else
		{	return false;
		}
	} //----- Fin de Remove

	void SetOfFigures::RemoveAll()
	// Algorithme :
	//
	{
		for(map<string, Figure *>::iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	delete mi->second;	
			}		
		}
		figures.clear();
	} //----- Fin de RemoveAll

    Figure* SetOfFigures::GetFigure(const string &n) const
    // Algorithme :
	//
	{
		map<string, Figure *>::const_iterator f = figures.find(n);
		if(f != figures.end())
		{	return f->second;
		}
		else
		{	return NULL;
		}
	} //----- Fin de GetFigure

	string SetOfFigures::Print() const
	// Algorithme :
	//
	{
		string p = "";
		int i=0, l = figures.size();
		for(map<string, Figure *>::const_iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	p += mi->second->Print();
				if(i < (l-1))
				{	p += "\n";
				}
			}
			i++;		
		}
		return p;
	} //----- Fin de Print
	
	void SetOfFigures::Move( const Vect &p )
	// Algorithme :
	//
	{
		for(map<string, Figure *>::const_iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	mi->second->Move(p);
			}		
		}
	} //----- Fin de Move

//------------------------------------------------- Surcharge d'opérateurs
	ostream& operator<<( ostream& out, const SetOfFigures &f )
	// Algorithme :
	//
	{
		out << f.Print();
		return out;
	}//----- Fin de operator << 

//-------------------------------------------- Constructeurs - destructeur
	SetOfFigures::SetOfFigures ( const SetOfFigures & unSetOfFigures ) : Figure(unSetOfFigures.GetName())
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <SetOfFigures>" << endl;
	#endif
		map<string, Figure *> ens = unSetOfFigures.GetFigures();
		for(map<string, Figure *>::iterator mi = ens.begin(); mi != ens.end(); ++mi)
		{	if(mi->second != NULL)
			{	figures[mi->first] = mi->second->Copy();
			}
		}
	} //----- Fin de SetOfFigures (constructeur de copie)


	SetOfFigures::SetOfFigures ( const string & name ) : Figure(name)
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au constructeur de <SetOfFigures>" << endl;
	#endif
	} //----- Fin de SetOfFigures


	SetOfFigures::~SetOfFigures ( )
	// Algorithme :
	//
	{
	#ifdef MAP
		cout << "Appel au destructeur de <SetOfFigures>" << endl;
	#endif
		for(map<string, Figure *>::iterator mi = figures.begin(); mi != figures.end(); ++mi)
		{	if(mi->second != NULL)
			{	delete mi->second;
				mi->second = NULL;
			}	
		}
		figures.clear();
	} //----- Fin de ~SetOfFigures


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
