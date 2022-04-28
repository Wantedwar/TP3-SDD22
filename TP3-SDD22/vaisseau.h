#pragma once
#include <string>

using std::string;

class vaisseau
{
	static int vnextid;
	int id;
	string modele = "";
	int capacite = 0;
	vaisseau(string modele, int capacite);
};

