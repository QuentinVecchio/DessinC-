#include <iostream>
#include <string>
#include "../../Source/Segment.h"
#include "../../Source/Vect.h"


using namespace std;

int main()
{
	Vect P1 (1,2);
	Vect P2 (3,4);
	Segment s1("sgm1",P1,P2);
	Vect P3 (4,5);
	cout <<s1.IsIn(P3) << endl;
	Vect P4 (0,1);
	cout <<s1.IsIn(P4) << endl;
	Vect P5 (3,3);
	cout <<s1.IsIn(P5) << endl;
	Vect P6 (2,3);
	cout <<s1.IsIn(P6) << endl;
	cout  <<s1 << endl;
	s1.Move(P4);
	cout <<s1 << endl;
	return 0;
}
