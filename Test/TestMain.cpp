/*************************************************************************
TestMain  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestMain> (fichier TestMain.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <chrono>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestMain.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
TestMain::test()
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
