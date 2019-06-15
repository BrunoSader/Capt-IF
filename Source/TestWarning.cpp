/*************************************************************************
TestWarning  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par VACHEZ
e-mail               : brice.vachez@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestWarning> (fichier TestWarning.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/TestWarning.h"
#include "../En-tete/Attribut.h"
#include "../En-tete/Decision.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
void TestWarning::testUnitaire()
{

    cout << "Tests de valeurs au delà d'un seuil" << endl << endl;
    testValeurSeuil();
    cout << "Appuyez sur <RETURN> pour continuer" << endl;
    getchar();


    cout << "Tests de création de decisions" << endl << endl;
    testCreerDecision();
    cout << "Appuyez sur <RETURN> pour continuer" << endl;
    getchar();
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TestWarning::testValeurSeuil()
{
    cout << "Création de 3 attributs" << endl;
    vector<Attribut> listeAttributs;
    listeAttributs.push_back(Attribut("O3", "mg/L", "l'ozone", 30));
    listeAttributs.push_back(Attribut("CH3NO2", "km/h", "la nitro", 280));
    listeAttributs.push_back(Attribut("N2O", "lol/mdr", "ce drole", 170));
    for (Attribut a : listeAttributs)
    {
        cout << a.getAttributeId () << " - Seuil : " << a.getValeurSeuil() << endl;
    }
    cout << endl;
    string attributs[] = {"O3", "CH3NO2", "N2O", "C4H8Cl2S", ""};
    float values[] = {30.5, 0, 170, -5, 140};
    string attendus[] = {"SUCCESS", "FAIL" ,"FAIL", "FAIL","FAIL"};
    Warning *w = new Warning();
    bool result; string obtenu; int note(0);
    for (int i = 0; i < 5; ++i)
    {
        cout << "AttributId : " << attributs[i] << " | Valeur : " << values[i] << endl;
        result = w->valeurAuDelaSeuil(attributs[i], values[i], listeAttributs);
        if(result) obtenu="SUCCESS"; else obtenu = "FAIL";
        cout << "Resultat attendu : " << attendus[i] << " | Resultat obtenu : " << obtenu << endl << endl;
        if (attendus[i] == obtenu) note++;
    }
    cout << "Score : " << note << "/5" << endl << endl;
    delete w;
}

void TestWarning::testCreerDecision()
{
    bool action1[] = {true, true, false, false};
    bool action2[] = {false, true, true, false};
    bool action3[] = {true, true, false, true};
    bool action4[] = {false, false, true, false};
    string attendus[] = {"SUCCESS","SUCCESS", "FAIL", "SUCCESS", "SUCCESS"};
    Decision d1 = Decision(action1, "");
    Decision d2 = Decision(action2, "");
    Decision d3 = Decision(action3, "");
    Decision d4 = Decision(action4, "");
    Warning *w = new Warning();
    unsigned int sizeL; string obtenu; int note(0);

    sizeL = w->getListeDecision().size();
    w->entrerDecision(d1, 10);
    if (w->getListeDecision().size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
    cout << "Taille precedente : " << sizeL << " | Taille actuelle : " << w->getListeDecision().size() << endl;
    cout << "Resultat attendu : " << attendus[0] << " | Resultat obtenu : " << obtenu << endl << endl;
    if (attendus[0] == obtenu) note++;

    sizeL = w->getListeDecision().size();
    w->entrerDecision(d2, 15);
    if (w->getListeDecision().size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
    cout << "Taille precedente : " << sizeL << " | Taille actuelle : " << w->getListeDecision().size() << endl;
    cout << "Resultat attendu : " << attendus[1] << " | Resultat obtenu : " << obtenu << endl << endl;
    if (attendus[1] == obtenu) note++;

    sizeL = w->getListeDecision().size();
    w->entrerDecision(d1, 10);
    if (w->getListeDecision().size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
    cout << "Taille precedente : " << sizeL << " | Taille actuelle : " << w->getListeDecision().size() << endl;
    cout << "Resultat attendu : " << attendus[2] << " | Resultat obtenu : " << obtenu << endl << endl;
    if (attendus[2] == obtenu) note++;

    sizeL = w->getListeDecision().size();
    w->entrerDecision(d3, 18);
    if (w->getListeDecision().size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
    cout << "Taille precedente : " << sizeL << " | Taille actuelle : " << w->getListeDecision().size() << endl;
    cout << "Resultat attendu : " << attendus[3] << " | Resultat obtenu : " << obtenu << endl << endl;
    if (attendus[3] == obtenu) note++;

    sizeL = w->getListeDecision().size();
    w->entrerDecision(d4, 18);
    if (w->getListeDecision().size() > sizeL) obtenu = "SUCCESS"; else obtenu = "FAIL";
    cout << "Taille precedente : " << sizeL << " | Taille actuelle : " << w->getListeDecision().size() << endl;
    cout << "Resultat attendu : " << attendus[4] << " | Resultat obtenu : " << obtenu << endl << endl;
    if (attendus[4] == obtenu) note++;

    cout << "Score : " << note << "/5" << endl << endl;
}
