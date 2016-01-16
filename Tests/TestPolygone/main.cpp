#include <iostream>
#include <string>
#include <vector>
#include "../../source/Splitter.h"

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	Splitter split(s, ' ');
	Splitter split2(s, ' ');
	cout << split.Get(1) << endl;
	cout << split.Get(3) << endl;
	cout << split.Get(9) << endl;
	cout << split.Count() << endl;
	getline(cin,s);
	split.SetPhrase(s);
	cout << split.Get(1) << endl;
	cout << split.Get(3) << endl;
	cout << split.Get(9) << endl;
	cout << split.Count() << endl;
	split2 = split;
	cout << split2.Get(1) << endl;
	cout << split2.Get(3) << endl;
	cout << split2.Get(9) << endl;
	cout << split2.Count() << endl;
	Splitter split3(split);
	cout << split3.Get(1) << endl;
	cout << split3.Get(3) << endl;
	cout << split3.Get(9) << endl;
	cout << split3.Count() << endl;
	return 0;
}