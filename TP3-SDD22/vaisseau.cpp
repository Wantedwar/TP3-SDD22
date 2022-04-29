#include "vaisseau.h"
#include <iostream>

int vaisseau::vnextid = -1;

vaisseau::vaisseau(string modele, int capacite)
{
	this->modele = modele;
	this->capacite = capacite;
	id = vnextid++;
	std::cout << "Vaisseau cree : " << modele << " " << capacite << std::endl;
}
 