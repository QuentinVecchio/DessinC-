#include <iostream>
#include <string>
#include <vector>
#include "../../source/Line.h"

using namespace std;

int main()
{
	string s, url = "http://intranet-if.insa-lyon.fr";
	getline(cin,s);
	Line l(s,url);
	Line l1(l);
	cout << l;
	cout << l1;
	getline(cin,s);
	Line l2(s,url);
	l1 = l2;
	cout << l2;
	cout << l1;
	return 0;
}