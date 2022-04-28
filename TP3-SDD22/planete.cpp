#include "planete.h"


int planete::nextid = -1;

planete::planete(string nom, int x, int y, int population, string nation, float prixcarburant)
{
	this->nom = nom;
	this->x = x;
	this->y = y;
	this->nation = nation;
	this->population = population;
	this->prixcarburant = prixcarburant;
	id = ++nextid;
	std::cout << "nouvelle planete : " << nom << "\nid : " << id << std::endl;
}




