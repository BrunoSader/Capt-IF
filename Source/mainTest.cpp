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
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <chrono>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel


#include "../En-tete/TestGestionCapteur.h"
#include "../En-tete/TestGestionMesure.h"
void testGlobalManuel();

void testPerf();

int main(int argc, char *argv[])
{
    cout << "Dans les tests suivants, SUCCESS signifie que l'application a pu effectuer l'action demandee" <<endl;
    cout << "FAIL signifie que l'application n'a pas pu effectuer cette action" << endl;
    cout << "Un test marque FAIL n'a donc pas echoue, c'est juste que l'application n'a pas pu reussir a faire ce qui est demande" << endl;
    cout << "Ce qui est parfois bien, on ne veut pas pouvoir supprmer un capteur inexistant" << endl;
    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();
    /*cout << "Tests de Gestion de Capteurs" << endl << endl;
    TestGestionCapteur *tgc = new TestGestionCapteur();
    tgc -> testUnitaire(string(argv[1]));
    delete tgc;*/

   /* cout << "Tests de Gestion de Mesures" << endl << endl;
    TestGestionMesure *tgm = new TestGestionMesure();
    tgm -> testUnitaire(string(argv[2]), string(argv[3]));
    delete tgm;*/

    cout << "Tests système" << endl << endl;
    testGlobalManuel();

	testPerf();
	return 0;
}



void testGlobalManuel()
{
    // Ajouter des mesures, des capteurs, pour les tests

    cout << "Ajout de valeurs, de capteurs, d'attributs, manuellement" << endl << endl;
    GestionCapteur *gc = new GestionCapteur();
    GestionMesure *gm = new GestionMesure();
    gc->ajouterCapteur(10, 10, "Desc");
    gc->ajouterCapteur(20, 30, "Desc");
    gc->ajouterCapteur(50, 80, "Desc");
    gm ->ajouterAttribut("O2","mg","description");
    gm ->ajouterAttribut("O3","mg","description");
    gm ->ajouterAttribut("O4","mg","description");
    double values[] = {100, -10, -10, 25, 350, 15, 250, 32, 21, 90};
    string attribute[] = {"O2", "O3", "02", "03", "04", "03", "04", "02", "01", "07"};
    string sensor[] = {"Sensor0", "Sensor1", "Sensor5", "Sensor0", "Sensor0", "Sensor1", "Sensor2", "Sensor0", "Sensor2", "Sensor4"};
    for (int i = 0; i < 10; ++i)
    {
        struct tm tm {};
        double valueS = values[i];
        string attributeId = attribute[i];
        string sensorId = sensor[i];
        tm.tm_year = 2019;
        tm.tm_mon = 6 ;
        tm.tm_mday = 12;
        tm.tm_hour = 19;
        tm.tm_min = 20;
        tm.tm_sec = 5*(i+1);
        gm->ajouterMesure(tm, sensorId, attributeId, valueS);
    }

    cout << "Etat des donnees enregistrees au debut" << endl << endl;
    cout << gm ->consulterMesure() << endl<< endl; // L'affichage a l'air chelou
    cout << gm ->consulterType() << endl<< endl;
    cout << gc->afficherCapteur() << endl<< endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();
    // Calculs de moyenne de valeur

    cout << "Calcul de différentes moyennes pour des capteurs et attributs" << endl << endl;
    int noteMoyenne(0);
    int result;
    double moyenne[] = {0, 66, 250, -10, -10, 2.5, -10};

    cout << "Capteur : Sensor1 | Attribut : 04" << endl;
    cout << "Valeur attendue : " << moyenne[0] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O4", "Sensor1")) << endl << endl;
    if (result == moyenne[0]) noteMoyenne++;
    cout << "Capteur : Sensor0 | Attribut : 02" << endl;
    cout << "Valeur attendue : " << moyenne[1] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O2", "Sensor0")) << endl<< endl;
    if (result == moyenne[1]) noteMoyenne++;
    cout << "Capteur : Sensor2 | Attribut : 04" << endl;
    cout << "Valeur attendue : " << moyenne[2] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O4", "Sensor2")) << endl<< endl;
    if (result == moyenne[2]) noteMoyenne++;
    cout << "Capteur : Sensor1 | Attribut : 05 (inexistant)" << endl;
    cout << "Valeur attendue : " << moyenne[3] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O5", "Sensor2")) << endl<< endl;
    if (result == moyenne[3]) noteMoyenne++;
    cout << "Capteur : unSensorId (inexistant) | Attribut : 01 (inexistant)" << endl;
    cout << "Valeur attendue : " << moyenne[4] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O1", "unSensorId")) << endl<< endl;
    if (result == moyenne[4]) noteMoyenne++;
    cout << "Capteur : Sensor1 | Attribut : 03" << endl;
    cout << "Valeur attendue : " << moyenne[5] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O3", "Sensor1")) << endl<< endl;
    if (result == moyenne[5]) noteMoyenne++;
    cout << "Capteur : Sensor2 | Attribut : 01" << endl;
    cout << "Valeur attendue : " << moyenne[6] << " | Valeur obtenue : ";
    cout << (result =  gm ->moyenneValAttribut("O1", "Sensor2")) << endl<< endl;
    if (result == moyenne[6]) noteMoyenne++;

    cout << endl << "Score : " << noteMoyenne << "/7" << endl <<endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();
    // Surveillance de casteurs

    cout << "Test de surveillance de capteurs" << endl << endl;

    bool resultSur; string resultStr;

    //On rajoute 10 mesures à notre capteur pour qu'il passe le test
    for (int i = 0; i < 10; ++i)
    {
        struct tm tm {};
        tm.tm_year = 2019;
        tm.tm_mon = 6 ;
        tm.tm_mday = 11-i;
        tm.tm_hour = 19;
        tm.tm_min = 20;
        tm.tm_sec = 2*(i+1);
        gm->ajouterMesure(tm, "Sensor2", "03", 15);
    }
    cout << gm ->consulterMesure() << endl<< endl; // L'affichage a l'air chelou

    cout << "On a rajoute assez de mesures a Sensor2 pour qu'il puisse passer le test" << endl << endl;
    int noteSur(0);
    string attendusSurveillance[] = {"FAIL", "FAIL", "SUCCESS", "FAIL"};
    for (int i = 0; i < 4; ++i)
    {
        string testedId = "Sensor"+to_string(i);
        cout << testedId << endl;
        cout << "Resultat attendu : " << attendusSurveillance[i] << " | Resultat obtenu : ";
        resultSur = gc ->surveillerCapteur(2, 0, 0, testedId, gm);
        if (resultSur) resultStr = "SUCCESS"; else resultStr = "FAIL";
        cout << resultStr << endl << endl;
        if(resultStr == attendusSurveillance[i]) noteSur++;
    }
    cout << "Score : " << noteSur << "/4" << endl << endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();

    cout << "Recuperer des mesures de capteurs" << endl << endl;

    int compteurParSensor, noteMesures(0);
    int compteurReel[] = {4, 2, 12, 0};
    for (int i = 0; i < 4; ++i)
    {
        compteurParSensor = 0;
        string sensorAct = "Sensor"+to_string(i);
        map<struct tm, map<string,double>> sensorValues = gm ->getMesure(sensorAct);
        for (map<struct tm, map<string,double>>::iterator it = sensorValues.begin(); it != sensorValues.end(); ++it)
        {
            compteurParSensor += it -> second.size();
        }
        cout << "Le capteur " << sensorAct << " a normalement " << compteurReel[i] << " mesures." << endl;
        cout << "On a trouve " << compteurParSensor << " mesures pour ce capteur." << endl << endl;
        if (compteurReel[i] == compteurParSensor) noteMesures++;
    }
    cout << "Score : " << noteMesures << "/4" << endl << endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();

    // Supprimer un capteur

    cout << "Tests de suppression de capteurs" << endl << endl;

    string sensorsTested[] = {"Sensor0", "Sensor1", "Sensor0", "Sensor6"};
    string attendusSup[] = {"SUCCESS","SUCCESS","FAIL","FAIL"};
    int noteSup(0);
    for (int i = 0; i < 4; ++i)
    {
        cout << "Tentative de suppression de " << sensorsTested[i] << endl;
        cout << "Resultat attendu : " << attendusSup[i] << " | Resultat obtenu : ";
        if (gc ->supprimerCapteur(2, 0, 0, sensorsTested[i])) resultStr = "SUCCESS"; else resultStr = "FAIL";
        cout << resultStr << endl << endl;
        if (resultStr == attendusSup[i]) noteSup++;
    }
    cout << "Score : " << noteSup << "/4" << endl << endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();

    // Test qu'on ne peut rien faire sur une capteur supprimé

    cout << "Peut-on recuperer un ID deja dans la base ?" << endl << endl;

    gc ->ajouterCapteur(10, 10, "desc");
    gc ->ajouterCapteur(30, 50, "desc2");
    cout << "Id dans la base" << endl;
    for (Capteur c : gc->listeCapteur)
    {
        cout << c.getSensorId() << "|";
    }
    cout << endl << endl;

    cout << "Essayer de surveiller un capteur supprime" << endl << endl;
    cout << "ATTENTION : bien différencier si la methode renvoie false parce que l'execution a donne false, ou parce que l capteur n'existe pas" << endl;
    cout << "Resultat attendu : FAIL | Resultat obtenu : ";
    if (gc->surveillerCapteur(2, 0, 0, "Sensor0", gm)) cout << "SUCCESS"; else cout << "FAIL";
    cout << endl;

    cout << "Appuyez sur <RETURN> pour continuer" << endl << endl;
    getchar();

    // Lire une donnée

}

void testPerf()
{
    	/* cout << "Test chargerFichier";
 	ERREUR :
	Si le fichier est inexistant
	Si le fichier est inaccessible en lecture
	Si le fichier est vide
	TOUT VA BIEN :
	Si le fichier existe, est accessible et si son contenu est conforme au format spécifié dans le sujet du TP */

	/// Test de performance :
	cout << "--------Test de performance--------"<<endl;
	fstream fichier3;
	string nomFichierDonnesCapteur = "new.csv";
	GestionMesure *gm = new GestionMesure();
	string chaine;
	string sacrifie;
	for(int k=10;k<1000000; k=k*10)
	{
		fichier3.open(nomFichierDonnesCapteur, ios::in);
		if (fichier3)
		{
			int i = 0;
			auto start = chrono::steady_clock::now();
			while (!fichier3.eof() && i<k)
			{
				stringstream ss;
				getline(fichier3, chaine);
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
				i++;
				//if(warning->valeurAuDelaSeuil(attributeId, valueS)){cout<<"WARNING!!! Votre capteur "<<sensorId<<" depasse le seuil de l'attribut "<<attributeId<<" avec une valeur de "<<valueS<<endl;}
				//else if(warning->calculerDonneePrevisionelle(gm->getMesure(sensorId),attributeId)){cout<<"WARNING!!! Votre capteur "<<sensorId<<" depassera le seuil de l'attribut "<<attributeId<<" dans 5 temps"<<endl;}
			}
			auto end = chrono::steady_clock::now();
			cout << "Elapsed time in milliseconds : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
		}
	}

}
