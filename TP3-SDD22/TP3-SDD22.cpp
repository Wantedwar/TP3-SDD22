// TP3-SDD22.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

//#include <iostream>
#include "fonctions.h"
#include <vector>


using std::vector;
using std::cout;

using std::cout;
using std::endl;

int main()
{
    int madjacence[NB][NB];
    planete* planetes[NB] = {nullptr};

    cout << "   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20" << endl;
    for (int i = 0; i < NB; i++) {//g pa trouvé comment init tout à -1
        cout << i+1 << " ";
        for (int j = 0; j < NB; j++) {
            madjacence[i][j] = -1;
            cout << madjacence[i][j] << " ";
        }
        cout << endl;
    }

    //Delta_1 589 596 297369 Delta 68.93
    //Delta_2 598 656 3671086 Delta 102.45
    //planete p1("Delta1", 589, 596, 297369, "Delta", 68.93);
    //planete p2("Delta2", 598, 656, 3671086, "Delta", 102.45);
    //Delta_3 645 870 5544317 Delta 66.75
    //Delta_4 737 666 7933529 Delta 116.21

    planetes[0] = new planete("Delta1", 589, 596, 297369, "Delta", 68.93);
    planetes[1] = new planete("Delta2", 598, 656, 3671086, "Delta", 102.45);
    planetes[2] = new planete("Delta3", 645, 870, 5544317, "Delta", 66.75);
    planetes[3] = new planete("Delta4", 737, 666, 7933529, "Delta", 116.21);

    //penser à supprimer planète
    remplir_madjacence(planetes, madjacence);
    cout << affichermadjacence(madjacence);
    //implémenter dfs et disjkstra
    //faire le fichier
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
