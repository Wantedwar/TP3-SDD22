// TP3-SDD22.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

//#include <iostream>
#include "fonctions.h"


using std::vector;
using std::cout;

using std::cout;
using std::endl;

int main()
{
    //////////INITS//////////
    int madjacence[NB][NB];
    planete* planetes[NB] = {nullptr};
    vaisseau* vaisseaux[NBV] = { nullptr };
    //cout << "   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20" << endl;
    for (int i = 0; i < NB; i++) {//g pa trouvé comment init tout à -1
        //cout << i+1 << " ";
        for (int j = 0; j < NB; j++) {
            madjacence[i][j] = -1;
            //cout << madjacence[i][j] << " ";
        }
        //cout << endl;
    }
    
    vector<vector<string>> guerres;
    std::ifstream transaction("Transactions_Simples.txt", std::ios::in);
    string ligne; // variable contenant chaque ligne lue 
    string mot;
    //cout << "t1" << endl;
    while (getline(transaction, ligne))
    {   
        // afficher la ligne à l'écran 
        //cout << "t2" << endl;
        string s = ligne;
        std::stringstream ss(s);
        string toks2[6]; //toks => tokens
        string sep;
        //ss >> toks[0] >> sep >> toks[1] >> sep >> toks[2] >> sep >> toks[3] >> sep >> toks[4] >> sep >> toks[5];
        ss >> toks2[0] >> toks2[1] >> toks2[2] >> toks2[3] >> toks2[4];
        //cout << "t3" << endl;
        cout << toks2[0] << " " << toks2[1] << " " << toks2[2] << " " << toks2[3] << " " << toks2[4] << endl;

        //#P FICHIER // Charge un système stellaire en mémoire (fichiers de planète)
        if (toks2[0] == "#P") {
            chargplanete(toks2[1], planetes);
            remplir_madjacence(planetes, madjacence);


        }
        //#V FICHIER // Charge les types de vaisseau en mémoire (fichier vaisseau) 
        else if (toks2[0] == "#V") {
            chargvaisseau(toks2[1], vaisseaux);

        }
        //?1  V  S  D // affiche  la réponse à  la  question:  existe-t-il  une  route  entre  les planètes S et D pour un vaisseau de type V
        else if (toks2[0] == "?1") {

            //cout << "...?1" << endl;


        }
        /*struct planete test;*/
        //?2  V  S  D
        //  Affiche  le  plus  court  chemin ainsi  que sa longueur,  c’estla distance que le vaisseau V doit parcourir pour se rendre de 
        //la planète S à D.
        else if (toks2[0] == "?2") {

            //cout << "...?2" << endl;

        }
        //?3  V S  D 
        //  Affiche  le chemin et  le  coût  du  trajet le moins  dispendieux que peut suivrele vaisseau V pour se rendre de la planète S à D.
        else if (toks2[0] == "?3") {
            //

        }
        // / N1 N2 // Applique un scénario de conflit spatial entre les nationsN1 et N2
        else if (toks2[0] == "/") {
            cout << "\n\nTOKS2ICIJKLMJKLMSGFG\n\n" << toks2[1];
            setguerre(toks2[1], toks2[2], guerres);

        }
        //&//  Affiche touteslesplanètes  (info  des planètes), tous  lestypes  de vaisseau (info des vaisseaux)ettouslesconflits entre deux nations.
        else if (toks2[0] == "&") {

            //cout << "...&" << endl;

        }

    }

    //ZONE DE TESTS
    cout << affichermadjacence(madjacence);
    //cout << idplanete(planetes, "Delta_1");
    cout << afficherplanete(*planetes[idplanete(planetes, "Delta_2")]);
    cout << afficherplanete(*planetes[idplanete(planetes, "Delta_2")]);
    cout << planetes[idplanete(planetes, "Delta_2")]->nation; 
    cout << afficherplanetes(planetes);
    cout << afficherguerre(guerres);


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
