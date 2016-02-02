#include <iostream>
#include <string>
#include "../../source/Command.h"

using namespace std;

int main()
{
	Command c("fait ci", "fait ca");
	cout << c.GetUnExecute() << endl;
	cout << c.GetExecute() << endl;
	return 0;
}