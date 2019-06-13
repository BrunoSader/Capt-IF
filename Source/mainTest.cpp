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

using namespace std;

//------------------------------------------------------ Include personnel


#include "../En-tete/TestGestionCapteur.h"
#include "../En-tete/TestGestionMesure.h"
void testGlobalManuel();

int main(int argc, char *argv[])
{
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
    cout << gm ->consulterMesure() << endl<< endl; // L'affichage a l'air chelou
    cout << gm ->consulterType() << endl<< endl;
    cout << gc->afficherCapteur() << endl<< endl;

    // Calculs de moyenne de valeur

    cout << "Calcul de différentes moyennes pour des capteurs et attributs" << endl << endl;
    int noteMoyenne(0);
    int result;
    double moyenne[] = {0, 66, 250, -10, -10, 2.5, -10};

    cout << "Valeur attendue : " << moyenne[0] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O4", "Sensor1")) << endl;
    if (result == moyenne[0]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[1] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O2", "Sensor0")) << endl;
    if (result == moyenne[1]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[2] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O4", "Sensor2")) << endl;
    if (result == moyenne[2]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[3] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O5", "Sensor2")) << endl;
    if (result == moyenne[3]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[4] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O1", "unSensorId")) << endl;
    if (result == moyenne[4]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[5] << " | Valeur obtenue : ";
    cout << (result = gm ->moyenneValAttribut("O3", "Sensor1")) << endl;
    if (result == moyenne[5]) noteMoyenne++;
    cout << "Valeur attendue : " << moyenne[6] << " | Valeur obtenue : ";
    cout << (result =  gm ->moyenneValAttribut("O1", "Sensor2")) << endl;
    if (result == moyenne[6]) noteMoyenne++;

    cout << endl << "Score : " << noteMoyenne << "/7" << endl <<endl;

    // Surveillance de casteurs

    cout << "Test de surveillance de capteurs" << endl << endl;

    bool resultSur; string resultStr;

    //On rajoute 6 mesures à notre capteur pour qu'il passe le test
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

    int noteSur(0);
    string attendusSurveillance[] = {"FAIL", "FAIL", "SUCCESS", "FAIL"};
    for (int i = 0; i < 4; ++i)
    {
        string testedId = "Sensor"+i;
        cout << "Resultat attendu : " << attendusSurveillance[i] << " | Resultat obtenu : ";
        resultSur = gc ->surveillerCapteur(2, 0, 0, testedId, gm);
        if (resultSur) resultStr = "SUCCESS"; else resultStr = "FAIL";
        cout << resultStr << endl << endl;
        if(resultStr == attendusSurveillance[i]) noteSur++;
    }
    cout << "Score : " << noteSur << "/4" << endl << endl;

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
        cout << "On a trouvé " << compteurParSensor << " mesures pour ce capteur." << endl << endl;
        if (compteurReel[i] == compteurParSensor) noteMesures++;
    }
    cout << "Score : " << noteMesures << "/4" << endl << endl;


    // Supprimer un capteur

    cout << "Tests de suppression de capteurs" << endl << endl;

    string sensorsTested[] = {"Sensor0", "Sensor1", "Sensor0", "Sensor6"};
    string attendusSup[] = {"SUCCESS","SUCCESS","FAIL","FAIL"};
    int noteSup(0);
    for (int i = 0; i < 4; ++i)
    {
        cout << "Tentative de suppression de " << sensorsTested[i] << endl;
        cout << "Resultat attendu : " << attendusSup[i] << " | Resultat obtenu : ";
        if (gc ->supprimerCapteur(2, 0, 0, sensorsTested[i])) resultStr = "SUCCESS"; else resultStr = "FALSE";
        cout << resultStr << endl << endl;
        if (resultStr == attendusSup[i]) noteSup++;
    }
    cout << "Score : " << noteSup << "/4" << endl << endl;

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
    // Lire une donnée

}
