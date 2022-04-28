#include "vaisseau.h"

int vaisseau::vnextid = -1;

vaisseau::vaisseau(string modele, int capacite)
{
	this->modele = modele;
	this->capacite = capacite;
	id = vnextid++;
}
