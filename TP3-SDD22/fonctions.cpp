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
    //cout << "x1 : " << p1->x << " x2 : " << p2->x << endl;
    //cout << "y2 : " << p1->y << " y2 : " << p2->y << endl;
	if (distance < 250) {
		madjacence[p1->id][p2->id] = distance;
		madjacence[p2->id][p1->id] = distance;
	}
    else {
        cout << "distance trop grande, arrete non cree" << endl;
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

string afficherplanetes(planete* planetes[NB])
{
    string retour;
    retour += "PLANETES\n";
    for (int i = 0; i < NB; i++) {
        retour += afficherplanete(*planetes[i]);
    }
    return retour;
}

void chargvaisseau(string vcharger, vaisseau* vaisseaux[NBV])
{
    ifstream vaisseau1(vcharger, ios::in);
    // <summary>
    string ligne; // variable contenant chaque ligne lue 
    string mot;
    //cout << "etape 1" << endl;
    int x = 0;
    while (getline(vaisseau1, ligne))
    {
        // afficher la ligne à l'écran 
        //cout << "etape 2" << endl;
        string s = ligne;
        stringstream ss(s);
        string toks2[3]; //toks => tokens
        string sep;
        //ss >> toks[0] >> sep >> toks[1] >> sep >> toks[2] >> sep >> toks[3] >> sep >> toks[4] >> sep >> toks[5];
        ss >> toks2[0] >> toks2[1];
        //cout << "etape 3" << endl;
        //cout << toks2[0] << endl;
        //cout << toks2[1] << endl;
        string test = toks2[0];
        
        vaisseaux[x] = new vaisseau(toks2[0], stoi(toks2[1]));
        /*struct planete test;*/

    }

}

string affichervaisseaux(vaisseau* vaisseaux[NBV])
{
    string retour;
    retour += "VAISSEAUX\n";
    for (int i = 0; i < NBV; i++) {
        retour += vaisseaux[i]->modele + to_string(vaisseaux[i]->capacite);
    }
    return retour;
}

void chargplanete(string pcharger, planete* planetes[]) {
    cout << "pcharger : " << pcharger << endl;
    ifstream planete1(pcharger, ios::in);
    // <summary>
    string ligne; // variable contenant chaque ligne lue 
    string mot;
    //getline(planete1, ligne);
    cout << pcharger << endl;
    //cout << "etape 1" << endl;
    int x = 0;
    while (getline(planete1, ligne))
    {
        // afficher la ligne à l'écran 
        //cout << "etape 2" << endl;
        string s = ligne;
        stringstream ss(s);
        string toks2[6]; //toks => tokens
        string sep;
        //ss >> toks[0] >> sep >> toks[1] >> sep >> toks[2] >> sep >> toks[3] >> sep >> toks[4] >> sep >> toks[5];
        ss >> toks2[0] >> toks2[1] >> toks2[2] >> toks2[3] >> toks2[4] >> toks2[5];
        //cout << "etape 3" << endl;
        cout << toks2[0] << " " << toks2[1] << " " << toks2[2] << " " << toks2[3] << " " << toks2[4] << " " << toks2[5] << endl;
        //string test = toks2[0];
        /*struct planete test;*/

        //cout << planetes[0]->nom;
        planetes[x] = new planete(toks2[0], std::stoi(toks2[1]), std::stoi(toks2[2]), std::stoi(toks2[3]), toks2[4], std::stof(toks2[5]));
        x++;
    }

}

string afficherplanete(planete plan)
{

    string retour;
    retour += plan.nom + " (id : " + to_string(plan.id) + ") " + to_string(plan.x) + " " + to_string(plan.y) + " " + plan.nation + " " + to_string(plan.population) + " " + to_string(plan.prixcarburant) + "\n";
    return retour;
}

void setguerre(string n1, string n2, vector<vector<string>>& guerres)
{
    guerres.push_back({ n1,n2 });
}

int checkguerre(string n1, string n2, vector<vector<string>>& guerres)
{
    int retour = 1;
    for (int i = 0; i < guerres.size(); i++) {
        if (guerres[i][0].compare(n1) && guerres[i][1].compare(n2) || guerres[i][0].compare(n2) && guerres[i][0].compare(n1)) {
            retour = 0;
            break;
        }
    }
        
    return retour;
}

int idplanete(planete* planetes[NB], string nmplan)
{
    int i=0;
    while (planetes[i]->nom.compare(nmplan) != 0)
        i++;
    return i;
}

string afficherguerre(vector<vector<string>>& guerres)
{
    string retour;
    retour += "GUERRES\n";
    for (int i = 0; i < guerres.size(); i++) {
        retour += guerres[i][0] + " " + guerres[i][1] + "\n";
    }

    return retour;
}

