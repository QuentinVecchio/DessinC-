#include <iostream>
#include <string>
#include <vector>
#include "../../source/Dessin.h"
#include "../../source/Rectangle.h"
#include "../../source/Vect.h"
#include "../../source/Segment.h"
#include "../../source/Polygon.h"

using namespace std;

int main()
{
	//	Constructeur
	Dessin d1("dessin1");
	Rectangle *r1 = new Rectangle("rectangle1", 0, 2, 2, 0);
	d1.Add(r1);
	//	Constructeur par copie
	Dessin d2(d1);
	d2.SetName("dessin2");
	//	Surcharge du =
	Dessin d3 = d1;
	d3.SetName("dessin3");
	//	Méthode Add
	Rectangle *r2 = new Rectangle("rectangle2", 0, 5, 5, 0);
	d1.Add(r2);
	Segment *s1 = new Segment("segment1",5,5,0,5);
	d1.Add(s1);
	Polygon *p = new Polygon("polygon1");
	p->Add(Vect(-1,5));
	p->Add(Vect(-2,2));
	p->Add(Vect(-2,-2));
	p->Add(Vect(1,-3));
	p->Add(Vect(3,1));
	d1.Add(p);
	//	Surcharge du << et Print
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	//	Méthode Move
	Vect p1(2,2);
	d1.Move(p1);
	cout << d1 << endl;
	//	Méthode Move 2
	Vect p2(2,2);
	d1.MoveFigure("rectangle2",p2);
	cout << d1 << endl;
	//	Méthode IsIn
	Vect p3(3,2);
	Vect p4(15,2);
	cout << d1.IsIn(p3) << endl;
	cout << d1.IsIn(p4) << endl;
	//	Méthode IsIn 2
	Vect p5(2,1);
	Vect p6(8,6);
	cout << d1.IsInFigure("rectangle1",p5) << endl;
	cout << d1.IsInFigure("rectangle2",p6) << endl;
	//	Méthode Remove
	cout << d1.Remove("rectangle2") << endl;
	cout << d1.Remove("rectangle3") << endl;
	cout << d1.Remove("rectangle1") << endl;
	d1.RemoveAll();
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	//	Méthode AddByCmd
	string cmd;
	for(int i=0;i<7;i++)
	{	getline(cin,cmd);
		d1.AddByCmd(cmd);
	}
	cout << d1 << endl;
	//	Méthode Save
	d1.Save("test.txt");
	//	Méthode Load
	d1.Load("save.txt");
	cout << d1 << endl;
	return 0;
}