#pragma once
#include "planete.h"
#include <string>
#include <fstream>
#include <sstream>
#define NB 4



void ajouterarrete(planete* p1, planete* p2,int madjacence[][NB]);
void remplir_madjacence(planete* planetes[NB],int madjacence[][NB]);
void bfs(planete* debut);
void dijkstra();
void affichergrille();
string affichermadjacence(int madjacence[][NB]);

void chargvaisseau(string vcharger);
void chargplanete(string pcharger);

string afficherplanete(planete plan);