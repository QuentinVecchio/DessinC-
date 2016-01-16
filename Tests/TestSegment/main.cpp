#include <iostream>
#include <string>
#include <vector>
#include "../../source/Log.h"

using namespace std;

int main()
{
	//Test sans filtre
	string url = "http://intranet-if.insa-lyon.fr";
	Log l("log.txt",url);
	l.MeilleuresAffluence(10);
	Log l1(l);
	l1.MeilleuresAffluence(10);
	Log l2("log2.txt",url);
	l2 = l1;
	l2.MeilleuresAffluence(10);
	//Test avec filtre heure
	Log l4("log.txt",url,true, 12);
	l4.MeilleuresAffluence(10);
	//Test avec filtre sans code erreur
	Log l5("log.txt",url,false);
	l5.MeilleuresAffluence(10);
	//Test avec filtre extension
	Log l6("log.txt",url,true,-1,true);
	l6.MeilleuresAffluence(10);
	return 0;
}