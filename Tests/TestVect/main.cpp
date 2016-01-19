#include <iostream>
#include "../../source/Vect.h"

using namespace std;

int main()
{
	Vect P1 (10,5);
	Vect P2 (14,7);
	P2 = P2 + P1*3 ;
	Vect P3 (P2);
	P2 = P2 * 10;
	cout << P1.Print() << endl << P2 << endl << P3 << endl;
	return 0;
}