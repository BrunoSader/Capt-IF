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
#include <map>
#include <ctime>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/GestionCapteur.h"
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"

int main(int argc, char *argv[])
{ 
	//le premier argument correspond au nom du fichier avec les différents types d'attributs 
	string nomFichierAttribut = string(argv[1]);
	//le second correspond à la description de capteurs
	string nomFichierDescriptionCapteur = string(argv[2]);
	//le dernier correspond aux des données capteurs 
	string nomFichierDonnesCapteur = string(argv[3]);

	//**********Stockage des Attributs dans le tableau de gestion mesure
	GestionMesure *gm = new GestionMesure();
	string chaine;
	string sacrifie;
	fstream fichier;
	fichier.open(nomFichierAttribut, ios::in);
	if (fichier)
	{
		getline(fichier, chaine);
		while (!fichier.eof())
		{
			stringstream ss;
			getline(fichier, chaine);
			ss << chaine;
			string id;
			string description;
			string unite;
			getline(ss, id, ';');
			getline(ss, unite, ';');
			getline(ss, description, ';');
			gm->ajouterAttribut(id, unite, description);
		}
	}
	// cout<<gm->consulterType()<<endl;

	//**********Stockage des Capteurs dans le tableau de gestion capteur
	GestionCapteur *gc = new GestionCapteur();
	fstream fichier2;
	fichier2.open(nomFichierDescriptionCapteur, ios::in);
	if (fichier2)
	{
		getline(fichier2, chaine);
		while (!fichier2.eof())
		{
			stringstream ss;
			getline(fichier2, chaine);
			ss << chaine;
			string id;
			int lattitude;
			int longitude;
			string description;
			getline(ss, id, ';');
			ss >> lattitude; 
			getline(ss, sacrifie, ';');
			ss >> longitude;
			getline(ss, sacrifie, ';');
			getline(ss, description, ';'); 
			gc->ajouterCapteur(id, lattitude, longitude, description);
		}
	}else{
		cout<<"marche pas"<<endl;
	}
	//cout<<gc->afficherCapteur()<<endl;
	//cout<<" "<<endl;
	Capteur c = gc->rechercherCapteur("Sensor0");
	gc->supprimerCapteur(c);
	//cout<<gc->afficherCapteur()<<endl;

	//**********Stockage des données des capteurs 

	fstream fichier3;
	fichier3.open(nomFichierDonnesCapteur, ios::in);
	if (fichier3)
	{
		getline(fichier3, chaine);
		while (!fichier3.eof())
		{
			stringstream ss;
			getline(fichier3, chaine);
			ss << chaine;
			string timestampS1;
			string timestampS2;
    			string sensorId;
    			string attributeId;    			
			double valueS;
			getline(ss, timestampS1, 'T');
			getline(ss, timestampS2, ';');
			getline(ss, sensorId, ';');
			getline(ss, attributeId, ';');
			ss >> valueS; 
			getline(ss, sacrifie, ';');
			struct tm tm;
			istringstream st(timestampS1+'-'+timestampS2);
    			st >> std::get_time(&tm, "%F-%T");
    			time_t timestamp = mktime(&tm);
			gm->ajouterMesure(timestamp, sensorId, attributeId, valueS);
		}
	}
	cout<<gm->consulterMesure()<<endl;

	return 0;
} //----- fin de main
