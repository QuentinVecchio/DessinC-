#include <iostream>
#include <string>
#include "../../source/Point.h"
#include "../../source/Segment.h"

using namespace std;

int main()
{
	Point P1 (1,2);
	Point P2 (3,4);
	Segment s1("sgm1",P1,P2);
	Point P3 (4,5);
	cout <<s1.IsIn(P3) << endl;
	Point P4 (0,1);
	cout <<s1.IsIn(P4) << endl;
	Point P5 (3,3);
	cout <<s1.IsIn(P5) << endl;
	Point P6 (2,3);
	cout <<s1.IsIn(P6) << endl;
	cout  <<s1 << endl;
	s1.Move(P4);
	cout <<s1 << endl;
	return 0;
}
