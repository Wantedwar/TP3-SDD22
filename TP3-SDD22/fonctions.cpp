#include "fonctions.h"

void ajouterarrete(planete* p1, planete* p2, int madjacence[][NB])
{
	int distance = sqrt((p1->x + p2->x) ^ 2 + (p1->y + p2->y) ^ 2);
	std::cout << "distance calculée entre" << p1->nom << " et " << p2->nom << " est : " << distance << std::endl;

}
