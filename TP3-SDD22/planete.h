#pragma once

#include <iostream>

using std::string;

struct planete
{
	static int nextid;
	int id;
	string nom;
	int x;
	int y;
	string nation;
	int population;
	float prixcarburant;
	///////////Constructeurs///////////
	planete(string nom, int x, int y, int population, string nation, float prixcarburant);

};






