/*************************************************************************
		   main  -  description
				 -------------------
	début        :
	copyright    :
	e-mail       :
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) -------------

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------ Include personnel


#include "../En-tete/TestGestionCapteur.h"
#include "../En-tete/TestGestionMesure.h"

int main(int argc, char *argv[])
{
    /*cout << "Tests de Gestion de Capteurs" << endl << endl;
    TestGestionCapteur *tgc = new TestGestionCapteur();
    tgc -> testUnitaire(string(argv[1]));
    delete tgc;*/

    cout << "Tests de Gestion de Mesures" << endl << endl;
    TestGestionMesure *tgm = new TestGestionMesure();
    tgm -> testUnitaire(string(argv[2]), string(argv[3]));
    delete tgm;
	return 0;
}
