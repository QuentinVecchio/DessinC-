#include <iostream>
#include <string>
#include <vector>
#include "../../source/Date.h"

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	Date d(s);
	Date d1(d);
	Date d3(s);
	cout << (d == d) << endl;
	cout << (d <= d) << endl;
	cout << (d1 >= d) << endl;
	cout << (d != d) << endl;
	cout << d << endl;
	cout << d1 << endl;
	getline(cin,s);
	d.SetDate(s);
	cout << d << endl;
	cout << (d < d1) << endl;
	cout << (d > d1) << endl;
	getline(cin,s);
	d.SetDate(s);
	cout << d << endl;
	getline(cin,s);
	d.SetDate(s);
	d3 = d;
	cout << d << endl;
	cout << d3 << endl;
	return 0;
}