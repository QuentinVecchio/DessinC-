#include <iostream>
#include <string>
#include <vector>
#include "../../source/Union.h"
#include "../../source/Rectangle.h"
#include "../../source/Vect.h"

using namespace std;

int main()
{
	//	Constructeur
	Union u1("union1");
	Rectangle *r1 = new Rectangle("rectangle1", 0, 2, 2, 0);
	u1.Add(r1);
	//	Constructeur par copie
	Union u2(u1);
	u2.SetName("union2");
	//	Surcharge du =
	Union u3 = u1;
	u3.SetName("union3");
	//	Méthode Add
	Rectangle *r2 = new Rectangle("rectangle2", 0, 5, 5, 0);
	u1.Add(r2);
	//	Surcharge du << et Print
	cout << u1 << endl;
	cout << u2 << endl;
	cout << u3 << endl;
	//	Méthode Move
	Vect p1(2,2);
	u1.Move(p1);
	cout << u1 << endl;
	//	Méthode IsIn
	Vect p3(3,2);
	Vect p4(15,2);
	cout << u1.IsIn(p3) << endl;
	cout << u1.IsIn(p4) << endl;
	//	Méthode Remove
	cout << u1.Remove("rectangle2") << endl;
	cout << u1.Remove("rectangle3") << endl;
	cout << u1.Remove("rectangle1") << endl;
	cout << u1 << endl;
	cout << u2 << endl;
	cout << u3 << endl;
	return 0;
}