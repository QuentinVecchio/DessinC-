#include <iostream>
#include "../../source/Vect.h"
#include "../../source/Polygon.h"

using namespace std;

int main()
{
	//Le constructeur
	Polygon p("polygon1");
	//La surcharge du =
	Polygon p1 = p;
	p1.SetName("polygon2");
	//Le constructeur par copie
	Polygon p2(p);
	p2.SetName("polygon3");
	//La surcharge du <<
	cout << p << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	//L'ajout d'un point
	p.Add(Vect(-1,5));
	p.Add(Vect(-2,2));
	p.Add(Vect(-2,-2));
	p.Add(Vect(1,-3));
	p.Add(Vect(3,1));
	//La méthode GetNbPoints()
	cout << p.GetNbPoints() << endl;
	//La méthode Move
	cout << p << endl;
	p.Move(Vect(2,2));
	cout << p << endl;
	//La méthode IsIn
	cout << p.IsIn(Vect(15,2)) << endl;
	cout << p.IsIn(Vect(0,0)) << endl;
	//La méthode IsConvexe
	cout << p.IsConvexe() << endl;
	return 0;
}