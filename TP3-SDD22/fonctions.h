#pragma once
#include "planete.h"
#define NB 20



void ajouterarrete(planete* p1, planete* p2,int madjacence[][NB]);
void bfs(planete debut);
void dijkstra();
void affichergrille();

string afficherplanete(planete plan);