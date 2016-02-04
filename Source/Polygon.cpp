/*************************************************************************
                           Polygon  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------- Réalisation de la classe <Polygon> (fichier Polygon.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polygon.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
typedef vector<Vect>::const_iterator ItListVect;
typedef vector<Vect> ListVect;

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


string Polygon:: Print() const
{
	string toReturn = "PC " + this->GetName();
	for(ItListVect itListPoints = listePoints.begin(); itListPoints != listePoints.end();++itListPoints)
	{
		toReturn += " "+itListPoints->Print();
	}
	return toReturn;
}


bool Polygon::IsIn( const Vect &p ) const
{
	Vect vect1 = listePoints[0]-listePoints[1];
	Vect vect2 = listePoints[1]-p;
	int prodv1 = Vect::ProdVect(vect1,vect2);
	int unsigned listSize= listePoints.size();

	for(int unsigned tabIndex=2;tabIndex<listSize;tabIndex++)
		{
			vect1 = listePoints[tabIndex-1]-listePoints[tabIndex];
			vect2 = listePoints[tabIndex]-p;
			int prodvcur = Vect::ProdVect(vect1,vect2);
			if (prodvcur*prodv1<0)
			{
				return false;
			}
		}
	vect1 = listePoints[listSize-1]-listePoints[0];
	vect2 = listePoints[0]-p;
	int prodvcur = Vect::ProdVect(vect1,vect2);
	if (prodvcur*prodv1<0)
		{
			return false;
		}
	return true;
}


void Polygon::Move( const Vect &dp )
{
	for(vector<Vect>::iterator iter = listePoints.begin(); iter != listePoints.end();++iter)
	{
		*iter = (*iter)+dp;
	}
}

Polygon* Polygon::Copy( ) const
// Algorithme :
//
{
	Polygon *s = new Polygon(*this);
	return s;
} //----- Fin de Copy

bool Polygon::IsConvexe( ) const
// Algorithme :
// on considére chauqe coté du polygone comme un vecteur orienté du point k-1 vers le point k;
// calcule des produit vecteurielle des vecteurs consécutifes
// on verifi qu'il sont tous de même signe.
// TODO eviter le boucles.
{
	Vect vect1 = listePoints[0]-listePoints[1];
	Vect vect2 = listePoints[1]-listePoints[2];
	int prodv1 = Vect::ProdVect(vect1,vect2);
	int unsigned listSize= listePoints.size();

	for(int unsigned tabIndex=3;tabIndex<listSize;tabIndex++)
	{
		vect1 = listePoints[tabIndex-2]-listePoints[tabIndex-1];
		vect2 = listePoints[tabIndex-1]-listePoints[tabIndex];
		int prodvcur = Vect::ProdVect(vect1,vect2);
		if (prodvcur*prodv1<0)
		{	return false;
		}
	}
	vect1 = listePoints[listSize-2]-listePoints[listSize-1];
	vect2 = listePoints[listSize-1]-listePoints[0];
	int prodvcur = Vect::ProdVect(vect1,vect2);
	if (prodvcur*prodv1<0)
	{	return false;
	}
	vect1 = listePoints[listSize-2]-listePoints[listSize-1];
	vect2 = listePoints[listSize-1]-listePoints[0];
	prodvcur = Vect::ProdVect(vect1,vect2);
	if (prodvcur*prodv1<0)
	{	return false;
	}
	return true;

}

int Polygon::GetNbPoints() const
// Algorithme :
//
{
	return listePoints.size();
} //----- Fin de la méthode GetNbPoints

void Polygon::Add(const Vect &p)
// Algorithme :
//
{
	listePoints.push_back(p);
} //----- Fin de la méthode Add

vector<Vect> Polygon::GetPoints() const
// Algorithme :
//
{
	return listePoints;
} //----- Fin de la méthode GetPoints

void Polygon::SetPoints(const vector<Vect> &list)
// Algorithme :
//
{
	listePoints = list;
} //----- Fin de la méthode SetPoints

void Polygon::RemoveAll()
// Algorithme :
//
{
	this->listePoints.clear();
} //----- Fin de la méthode RemoveAll

//------------------------------------------------- Surcharge d'opérateurs
Polygon & Polygon::operator = ( const Polygon & aPolygon )
// Algorithme :
//
{
	for(ItListVect itListPoints = aPolygon.listePoints.begin(); itListPoints != aPolygon.listePoints.end();++itListPoints)
	{
		listePoints.push_back(*itListPoints);
	}
    SetName(aPolygon.GetName());
	return (*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Polygon::Polygon ( const Polygon & aPolygon):
		Figure(aPolygon.GetName())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polygon>" << endl;
#endif
	for(ItListVect itListPoints = aPolygon.listePoints.begin(); itListPoints != aPolygon.listePoints.end();++itListPoints)
	{
		listePoints.push_back(*itListPoints);
	}

} //----- Fin de Polygon (constructeur de copie)


Polygon::Polygon( string nom):
		Figure(nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygon>" << endl;
#endif

} //----- Fin de Polygon



Polygon::~Polygon ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polygon>" << endl;
#endif
} //----- Fin de ~Polygon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
