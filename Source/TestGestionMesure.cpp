/*************************************************************************
TestGestionMesure  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestGestionMesure> (fichier TestGestionMesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/TestGestionMesure.h"
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
void TestGestionMesure::testUnitaire(string filename1, string filename2)
{


    cout << "Test de l'ajout d'attributs par fichier" << endl;
	/* ERREUR :
	Si le fichier qui contient la liste de capteurs est vide
	Si le fichier qui contient la liste de capteurs est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier est accessible et non vide*/
	testFichierAtt(filename1);

	cout << "Test de l'ajout de mesures par fichier" << endl;
	testFichierMes(filename2);

	cout << "Test de l'ajout d'attributs manuellement" << endl;
	testAjouterAtt();

	//cout << "Test consulterDonnées";
	/*ERREUR :
	Si le fichier qui contient la liste des mesures est vide
	Si le fichier qui contient la liste des mesures est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier qui contient la liste des mesures est accessible et non vide*/

	//cout << "Test donneesSimilaires";
	/*ERREUR :
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si la valeur n'est pas renseignée
	TOUT VA BIEN :
	Si  peu de données sont renvoyées lorsque l'intervalle de confiance est faible
	Si beaucoup de données sont renvoyées lorsque l'intervalle de confiance est grand*/

	//cout << "Test getMesureCapteur";
	/*ERREUR :
	Si les coordonnées indiquées n'existent pas
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si la date indiquée est inexistante
	Si l'horaire indiqué n'est pas entier
	Si aucune mesure ne correspond à la recherche
	TOUT VA BIEN :
	Si on obtient les résultats attendus en indiquant un intervalle de coordonnées
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant un intervalle horaire
	Si on obtient les résultats attendus en indiquant un ID de capteur existant
	Si on obtient les résultats attendus en indiquant un ID d'attribut existant pour l'ID du capteur
	Si on obtient les résultats attendus en combinant les éléments précédents, pour des valeurs extrèmes et intermédiaires*/

	//cout << "Test moyenneValAttribut";
	/*ERREUR :
	Si les dates indiquées sont inexistantes
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si aucune mesure ne correspond à la recherche
	Si une seule mesure correspond à la recherche
	TOUT VA BIEN :
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant une date
	Si on obtient les résultats attendus lorsqu'ils sont nombreux
	Si on obtient les résultats attendus lorsqu'ils sont peu nombreux */

	//cout << "Test genererGraph";
	/*ERREUR :
	Si les dates indiquées sont inexistantes
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si aucune mesure ne correspond à la recherche
	Si une seule mesure correspond à la recherche
	TOUT VA BIEN :
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant une date
	Si on obtient les résultats attendus lorsqu'ils sont nombreux
	Si on obtient les résultats attendus lorsqu'ils sont peu nombreux */

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TestGestionMesure::testAjouterAtt() // Quand est-ce qu'on change le seuil d'un attribut ajouté comme ça ?
{
    string ids[] = {"02", "", "03", "02", "SO4"};
    string unites[] = {"mg/L", "km/h", "b/s", "bpm", "Hz/km"};
    string descs[] = {"osef","osef","osef","osef","osef"};
    //float seuils[] = {3, 50, 10, 7, -1};
    string attendus[] = {"SUCCESS", "FAIL", "SUCCESS", "FAIL", "SUCCESS"};
    GestionMesure *gm = new GestionMesure();
    unsigned int taille; string resString; int note(0);
    for (int i = 0; i < 5; ++i)
    {
        cout << "Résultat attendu : " << attendus[i] << endl;
        taille = gm->listeTypeMesure.size();
        gm ->ajouterAttribut(ids[0], unites[i], descs[i]);
        if (gm->listeTypeMesure.size() > taille) resString = "SUCCESS"; else resString = "FAIL";
        cout << "Résultat obtenu : " << resString << endl << endl;
        if (resString == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gm;

}


void TestGestionMesure::testFichierAtt(string filename)
{
    cout << "Fichier testé : " << filename << endl;
    GestionMesure *gm = new GestionMesure();
    string chaine;
    string sacrifie;
    ifstream fichier;
    fichier.open(filename);
    if (fichier)
    {
        int countLine(0);
        while (getline(fichier, chaine))
        {
            ++countLine;
            stringstream ss;
            ss << chaine;
            string id;
            string description;
            string unite;
            getline(ss, id, ';');
            getline(ss, unite, ';');
            getline(ss, description, ';');
            gm->ajouterAttribut(id, unite, description);
        }
		int sizeList = gm->getListeAttribut().size();
		if (sizeList == 0)
        {
            cout << "Aucun capteur n'a pu être trouvé dans ce fichier" << endl;
        }
        else
        {
            cout << "Nous avoos pu enregistrer " << sizeList << " attributs. Le fichier faisait " << countLine << " lignes." << endl;
        }
    }
    else
    {
            cout << "Le fichier est inaccessible en lecture ou n'existe pas" << endl;
    }
    cout << endl;
    delete gm;
}

void TestGestionMesure::testFichierMes(string filename)
{
    cout << "Fichier testé : " << filename << endl;
    GestionMesure *gm = new GestionMesure();
	fstream fichier3;
	fichier3.open(filename, ios::in);
	ofstream myfile;
    myfile.open ("lectureAleatoire.csv");
    int countL(0);
    if (fichier3)
    {
        string chaine;
        string sacrifie;
        while (getline(fichier3, chaine))
        {
            stringstream ss;
            ++countL;
            ss << chaine;
            int annee;
            int mois;
            int jour;
            int heure;
            int minutes;
            double secondes;
            string sensorId;
            string attributeId;
            double valueS;
            ss >> annee;
            getline(ss, sacrifie, '-');
            ss >> mois;
            getline(ss, sacrifie, '-');
            ss >> jour;
            getline(ss, sacrifie, 'T');
            ss >> heure;
            getline(ss, sacrifie, ':');
            ss >> minutes;
            getline(ss, sacrifie, ':');
            ss >> secondes;
            getline(ss, sacrifie, ';');
            getline(ss, sensorId, ';');
            getline(ss, attributeId, ';');
            ss >> valueS;
            getline(ss, sacrifie, ';');
            struct tm tm {};
            tm.tm_year = annee;
            tm.tm_mon = mois ;
            tm.tm_mday = jour ;
            tm.tm_hour = heure;
            tm.tm_min = minutes;
            tm.tm_sec = secondes;
            gm->ajouterMesure(tm, sensorId, attributeId, valueS);
        }

        myfile << gm -> consulterMesure(gm->listeMesure);
        myfile.close();
        ifstream myFileRead;
        myFileRead.open("lectureAleatoire.csv");
        int compteur = count(istream_iterator<string>(myFileRead), istream_iterator<string>(), "Valeur");
        cout << "Nous avons lu " << compteur << " mesures. Le fichier faisait " << countL << " lignes. "<< endl;
    }
    else
    {
        cout << "Nous n'avons pas pu ouvrir ce fichier" << endl;
    }
    cout << endl;
	delete gm;
}
