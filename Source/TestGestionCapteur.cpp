/*************************************************************************
TestGestionCapteur  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestGestionCapteur> (fichier TestGestionCapteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include "../En-tete/Capteur.h"
#include "../En-tete/GestionCapteur.h"
#include "../En-tete/TestGestionCapteur.h"
using namespace std;

//------------------------------------------------------ Include personnel


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

    TestGestionCapteur::TestGestionCapteur(){}

    TestGestionCapteur::~TestGestionCapteur() {}

//----------------------------------------------------- Méthodes publiques

void TestGestionCapteur::testUnitaire(string filename)
{

    cout << "Test de l'ajout de capteurs par fichier" << endl;
	/* ERREUR :
	Si le fichier qui contient la liste de capteurs est vide
	Si le fichier qui contient la liste de capteurs est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier est accessible et non vide*/
	testFichier(filename);

    cout << endl << "Test de l'ajout manuel de capteurs" << endl;
	testAjouter();

    cout << endl << "Test de la recherche de capteurs par ID" << endl;
	testRechercheID();

	cout << endl << "Test de la recherche de capteurs par lattitude / longitude" << endl;
	testRechercheLatLng();

    cout << endl << "Test de la suppression de capteurs par ID" << endl;
	testSuppressionID();

	cout << endl << "Test de la suppression de capteurs par lattitude / longitude" << endl;
	testSuppressionLatLng();
	// Problèmes de segmentation fault ici



    // Note to Self : Surveiller Capteurs et Capteurs Similaires dans les tests Système

	//cout << "Test de consulterCapteurs" << endl;

	//cout << "Test de ajouterCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est déjà existant
	Si les latitude et longitude du capteur sont impossibles
	?? A FAIRE ?? Si les données du capteur ne sont pas consultables :  il n'est pas présent en mémoire ou non fonctionnel
	TOUT VA BIEN :
	Si le capteur a un ID inexistant, que sa localisation est possible et que ses données sont consultables.*/

	//cout << "Test de supprimerCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si on peut encore trouver le capteur dans la liste
	Si on peut encore le surveiller
	Si on ne peut plus récupérer les données dans le fichier data
	TOUT VA BIEN :
	Si le capteur a un ID existant, qu'on ne peut plus le surveiller ou le trouver dans la liste, mais qu'on peut récupérer ses données dans le fichier data*/

	//cout << "Test de rechercherCapteur" ;
	/* ERREUR :
	Si les coordonnées indiquées sont erronées
	TOUT VA BIEN :
	Si deux capteurs sont à la même distance du point indiqué
	Si un capteur est proche de la position indiquée */

	//cout << "Test de surveillerCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si l'ID indiqué correspond à un capteur non fonctionnel
	TOUT VA BIEN :
	Si l'ID indiqué existe et correspond à un capteur fonctionnel */

	//cout << "Test de capteursSimilaires" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si aucun capteur similaire n'est trouvé
	TOUT VA BIEN :
	Si avec un grand intervalle de confiance, beaucoup de capteurs similaires sont renvoyés
	Si avec un petit intervalle de confiance, peu de capteurs similaires sont renvoyés. */

}


//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées

void TestGestionCapteur::testFichier(string filename)
{
    cout << "Fichier testé : " << filename << endl;
	ifstream fichier;
	fichier.open(filename);
	if (fichier)
    {
        vector<Capteur> listCapteur;
        string chaine;
        string sacrifie;
        bool isOk = true;
        int countLine(0);
        while (getline(fichier, chaine))
        {
            isOk = true;
            ++countLine;
            stringstream ss;
			ss << chaine;
			string id;
			float lattitude;
			float longitude;
			string description;
			getline(ss, id, ';');
			ss >> lattitude;
			getline(ss, sacrifie, ';');
			ss >> longitude;
			getline(ss, sacrifie, ';');
			getline(ss, description, ';');
			if (lattitude ==0 || longitude ==0) isOk= false;
			if (isOk)
            {
                listCapteur.push_back(Capteur(id, longitude, lattitude, description));
            }
		}
		int sizeList = listCapteur.size();
		if (sizeList == 0)
        {
            cout << "Aucun capteur n'a pu être trouvé dans ce fichier" << endl;
        }
        else
        {
            cout << "Nous avoos pu enregistrer " << sizeList << " capteurs. Le fichier faisait " << countLine << " lignes." << endl;
        }
    }
    else
    {
            cout << "Le fichier est inaccessible en lecture ou n'existe pas" << endl;
    }
    cout << endl;
}

void TestGestionCapteur::testAjouter()
{
    int note = 0;
    GestionCapteur *gc = new GestionCapteur();
    float lats[] = {-180, 200, 0, 15, 30};
    float longs[] = {-180, 50, 70, 300, -15};
    string descs[] = {"", "Ceci est un capteur", "nananananana Capt Air", "description", ""};
    string attendus[] = {"FAIL", "FAIL", "SUCCESS", "FAIL", "FAIL"};
    unsigned int sizeL; string obtenu;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Latitude testee : " << lats[i] << " | Longitude testee : " << longs[i] << endl;
        cout << "Résultat attendu : " << attendus[i] << endl;
        sizeL = gc -> listeCapteur.size();
        gc -> ajouterCapteur(lats[i], longs[i], descs[i]);
        if (gc -> listeCapteur.size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
        cout << "Résultat obtenu : " << obtenu << endl << endl;
        if (obtenu == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gc;
}

void TestGestionCapteur::testRechercheID()
{
    int note = 0;
    GestionCapteur *gc = new GestionCapteur();
    for (int i = 0; i < 5; ++i)
    {
        gc -> ajouterCapteur(10*i, 10*i, "Capteur "+i);
    }
    string ids[] = {"Sensor0", "unCapteurID", "Sensor0", "Sensor7", "Sensor1"};
    string attendus[] = {"SUCCESS", "FAIL", "SUCCESS", "FAIL", "SUCCESS"};
    string resString; Capteur c;
    for (int i = 0; i < 5; ++i)
    {
        cout << "On recherche la presence de " << ids[i] << " dans la base. " << endl;
        cout << "Résultat attendu : " << attendus[i] << endl;
        c = gc -> rechercherCapteur(ids[i]);
        resString = "FAIL";
        for ( Capteur capt : gc -> listeCapteur )
        {
            if (capt.getSensorId() == c.getSensorId())
            {
                resString = "SUCCESS";
                break;
            }
        }
        cout << "Résultat obtenu : " << resString << endl << endl;
        if (resString == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gc;
}
/*
void TestGestionCapteur::testRechercheLatLng()
{
    int note = 0;
    GestionCapteur *gc = new GestionCapteur();
    for (int i = 0; i < 5; ++i)
    {
        gc -> ajouterCapteur(10*i, 10*i, "Capteur "+i);
    }
    double lats[] = {0, 30, 30, 70, -20};
    double longs[] = {0, 30, 30, 70, -20};
    string attendus[] = {"SUCCESS", "SUCCESS", "SUCCESS", "SUCCESS", "SUCCESS"}; // On ne peut pas ne rien trouver
    string resString; Capteur c;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Résultat attendu : " << attendus[i] << endl;
        c = gc -> rechercherCapteur(lats[i], longs[i]);
        resString = "FAIL";
        for ( Capteur capt : gc -> listeCapteur )
        {
            if (capt.getSensorId() == c.getSensorId())
            {
                resString = "SUCCESS";
                break;
            }
        }
        cout << "Résultat obtenu : " << resString << endl << endl;
        if (resString == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gc;
}
*/
void TestGestionCapteur::testSuppressionID()
{
    int note = 0;
    GestionCapteur *gc = new GestionCapteur();
    for (int i = 0; i < 5; ++i)
    {
        gc -> ajouterCapteur(10*i, 10*i, "Capteur "+i);
    }
    string ids[] = {"Sensor0", "unCapteurID", "Sensor0", "Sensor7", "Sensor1"};
    string attendus[] = {"SUCCESS", "FAIL", "FAIL", "FAIL", "SUCCESS"};
    bool res; string resString;
    for (int i = 0; i < 5; ++i)
    {
        cout << " On cherche a supprimer " << ids[i] << " de la base." << endl;
        cout << "Résultat attendu : " << attendus[i] << endl;
        res = gc -> supprimerCapteur(2, 0, 0, ids[i]);
        if(res) resString = "SUCCESS"; else resString = "FAIL";
        cout << "Résultat obtenu : " << resString << endl << endl;
        if (resString == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gc;
}
/*
void TestGestionCapteur::testSuppressionLatLng()
{
    int note = 0;
    GestionCapteur *gc = new GestionCapteur();
    for (int i = 0; i < 5; ++i)
    {
        gc -> ajouterCapteur(10*i, 10*i, "Capteur "+i);
    }
    cout << gc -> afficherCapteur() << endl;
    float lats[] = {0, 30, 35, -200, -20};
    float longs[] = {0, 30, 35, -200, -20};
    string attendus[] = {"SUCCESS", "SUCCESS", "FAIL", "FAIL", "FAIL"};
    bool res; string resString;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Résultat attendu : " << attendus[i] << endl;
        res = gc -> supprimerCapteur(1, lats[i], longs[i], "osef/20");
        cout << gc -> afficherCapteur() << endl;
        if(res) resString = "SUCCESS"; else resString = "FAIL";
        cout << "Résultat obtenu : " << resString << endl << endl;
        if (resString == attendus[i]) note++;
    }
    cout << "Score : " << note << "/5" << endl;
    delete gc;
}
*/
