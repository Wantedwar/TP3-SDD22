#pragma once
#include "planete.h"
#include "vaisseau.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#define NB 20
#define NBV 4

using std::vector;

void ajouterarrete(planete* p1, planete* p2,int madjacence[][NB]);
void remplir_madjacence(planete* planetes[NB],int madjacence[][NB]);
void bfs(planete* debut);
void dijkstra();
void affichergrille();
string affichermadjacence(int madjacence[][NB]);

string afficherplanetes(planete* planetes[NB]);

void chargvaisseau(string vcharger, vaisseau* vaisseaux[NBV]);
void chargplanete(string pcharger, planete *planetes[NB]);
string affichervaisseaux(vaisseau* vaisseaux[NBV]);

string afficherplanete(planete plan);


//TODO detruires planetes
void setguerre(string n1, string n2, vector<vector<string>>& guerres);
int checkguerre(string n1, string n2, vector<vector<string>>& guerres);//renvoie 0 ou 1 mais pas de conversion à faire, ou renvoie 10000 jsp
int idplanete(planete* planetes[NB], string nmplan);
string afficherguerre(vector<vector<string>>& guerres);

string affichertout();