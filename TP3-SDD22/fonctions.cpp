#include "fonctions.h"

//using std::ifstream;
//using std::stringstream;
//using std::cout;
//using std::endl;
using namespace std;

void ajouterarrete(planete* p1, planete* p2, int madjacence[][NB])
{
	int distance = sqrt((p1->x + p2->x) ^ 2 + (p1->y + p2->y) ^ 2);
	std::cout << "distance calculee entre " << p1->nom << " et " << p2->nom << " est : " << distance << std::endl;
	if (distance < 100) {
		madjacence[p1->id][p2->id] = distance;
		madjacence[p2->id][p1->id] = distance;
	}
}

void remplir_madjacence(planete* planetes[NB], int madjacence[][NB])
{
    int x = 1;
    while (planetes[x] != nullptr && x < NB) {//pas opti mais balec
        for (int i = 0; i < x; i++) {
            ajouterarrete(planetes[x], planetes[i], madjacence);
        }
        x++;
    }   
}


string affichermadjacence(int madjacence[][NB]) {
    string retour;
    retour += "    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n";
    for (int i = 0; i < NB; i++) {
        retour += std::to_string(i + 1);
        if (i < 9) retour += "  ";
        else retour += " ";
        for (int j = 0; j < NB; j++) {
            if (madjacence[i][j] == -1) {
                retour += " x ";
            }
            else
            {
                retour += " " + std::to_string(madjacence[i][j]) + " ";
            }
        }
        retour += "\n";
    }
    return retour;
}

void chargvaisseau(string vcharger)
{
    ifstream vaisseau1(vcharger, ios::in);
    // <summary>
    string ligne; // variable contenant chaque ligne lue 
    string mot;
    //getline(vaisseau1, ligne);
    cout << "etape 1" << endl;
    while (getline(vaisseau1, ligne))
    {
        // afficher la ligne à l'écran 
        cout << "etape 2" << endl;
        string s = ligne;
        stringstream ss(s);
        string toks2[3]; //toks => tokens
        string sep;
        //ss >> toks[0] >> sep >> toks[1] >> sep >> toks[2] >> sep >> toks[3] >> sep >> toks[4] >> sep >> toks[5];
        ss >> toks2[0] >> toks2[1];
        cout << "etape 3" << endl;
        cout << toks2[0] << endl;
        cout << toks2[1] << endl;
        string test = toks2[0];
        /*struct planete test;*/

    }

}

void chargplanete(string pcharger) {
    ifstream planete1(pcharger, ios::in);
    // <summary>
    string ligne; // variable contenant chaque ligne lue 
    string mot;
    //getline(planete1, ligne);
    cout << "etape 1" << endl;
    while (getline(planete1, ligne))
    {
        // afficher la ligne à l'écran 
        cout << "etape 2" << endl;
        string s = ligne;
        stringstream ss(s);
        string toks2[6]; //toks => tokens
        string sep;
        //ss >> toks[0] >> sep >> toks[1] >> sep >> toks[2] >> sep >> toks[3] >> sep >> toks[4] >> sep >> toks[5];
        ss >> toks2[0] >> toks2[1] >> toks2[2] >> toks2[3] >> toks2[4];
        cout << "etape 3" << endl;
        cout << toks2[0] << endl;
        cout << toks2[1] << endl;
        cout << toks2[2] << endl;
        cout << toks2[3] << endl;
        cout << toks2[4] << endl;
        string test = toks2[0];
        /*struct planete test;*/

    }
}