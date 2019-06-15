/*************************************************************************
		   main  -  description
				 -------------------
	début        :
	copyright    :
	e-mail       :
*************************************************************************/

//---------- Réalisation du module <LectureFichier> (fichier LectureFichier.cpp) -------------

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//------------------------------------------------------ Include personnel

#include "../En-tete/LectureFichier.h"
#include "../En-tete/Warning.h"

//****************************************************** Variables globales
string chaine;
string sacrifie;
//constructeur
LectureFichier::LectureFichier(GestionMesure* gm, GestionCapteur* gc, string nomFichierAttribut, string nomFichierDonnesCapteur, string nomFichierDescriptionCapteur, Warning* warning) : gm(gm), gc(gc), nomFichierAttribut(nomFichierAttribut), nomFichierDonnesCapteur(nomFichierDonnesCapteur), nomFichierDescriptionCapteur(nomFichierDescriptionCapteur), warning(warning)
{}

//Lecture du fichier Attribut
int LectureFichier::lectureAttribut(){

				fstream fichier;
				fichier.open(nomFichierAttribut, ios::in);
				int seuil;
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
						    if ("O3"==id)
						    {
							seuil=180;
						    }
						    else if ("NO2"==id)
						    {
							seuil=200;
							    }
						    else if ("SO2"==id)
						    {
							seuil=300;
						    }
						    else if ("PM10"==id)
						    {
							seuil=50;
						    }
						    else{ seuil = 0; }
								if(id != "") gm->ajouterAttribut(id, unite, description, seuil);
					}
				}else{
					cout<<"Ne fonctionne pas"<<endl;
				}
				return seuil;
}

	//**********Stockage des Capteurs dans le tableau de gestion capteur
	void LectureFichier::lectureCapteur(){
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
							double lattitude;
							double longitude;
							string description;
							getline(ss, id, ';');
							ss >> longitude;
							getline(ss, sacrifie, ';');
							ss >> lattitude;
							getline(ss, sacrifie, ';');
							getline(ss, description, ';');
							if(id != "") gc->ajouterCapteur(id, lattitude, longitude, description);
						}
					}else{
						cout<<"Ne fonctionne pas"<<endl;
					}
}

//Méthode pour la gestion des warnings pendant la lecture des données

void gestionDesDecisions (Warning *wr, double valeur, string sensorId)
{
	string read;
	bool aucuneDecision = true;
	cout<<"Voulez vous qu'on vous propose une solution? (oui)"<<endl;
	cin>>read;
	if(read=="oui")
	{
		Decision decision_propose=wr->proposerDecision();
		if(decision_propose.getNote()>2)
		{
			bool* action = decision_propose.getAction();
			cout<<"---On vous propose---"<<endl;
			if(action[0]) cout<<"Alterner les voitures d'imatriculation paire ou impaire"<<endl;
			if(action[1]) cout<<"Transport en commun gratuit pour tous pendant 3 jours"<<endl;
			if(action[2]) cout<<"Favoriser le co-voiturage avec des payages gratuits"<<endl;
			if(action[3]) cout<<"Augmenter les prix des polluants"<<endl;
			aucuneDecision = false;
		} else cout<<"Aucune proposition ne peut etre faite a ce moment"<<endl;
	}
		if(aucuneDecision){
		cout<<"Voulez vous entrer une decision? (oui)"<<endl;
		cin>>read;
		if(read=="oui")
		{
			bool *action = new bool[4];
			cout<<"Alterner les voitures d'imatriculation paire ou impaire (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[0]=true;
			cout<<"Transport en commun gratuit pour tous pendant 3 jours (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[1]=true;
			cout<<"Favoriser le co-voiturage avec des payages gratuits (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[2]=true;
			cout<<"Augmenter les prix des polluants (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[3]=true;
			Decision *laDecision = new Decision(action,sensorId);
			wr->entrerDecision(*laDecision,valeur);
		}
	}
}

	//**********Stockage des données des capteurs
	void LectureFichier::lectureDonneesCapteur(){
						fstream fichier3;
						fichier3.open(nomFichierDonnesCapteur, ios::in);

						ofstream myfile;
					  myfile.open ("lectureAleatoire.csv");
						for(int k=10; k<100000000; k=k*5)
						{

						int i = 0;
							if (fichier3)
							{
								while (!fichier3.eof() )
								{
									stringstream ss;
									getline(fichier3, chaine);
									if(i++ > 15){
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

									if(sensorId != "")gm->ajouterMesure(tm, sensorId, attributeId, valueS);

									if(warning->valeurAuDelaSeuil(attributeId, valueS, gm->getListeAttribut())){

											if(i < 3){
														if(warning->valeurAuDelaSeuil(attributeId, valueS, gm->getListeAttribut())){
															cout<<"WARNING!!! Votre capteur "<<sensorId<<" depasse le seuil de l'attribut "<<attributeId<<" avec une valeur de "<<valueS<<endl;
															gestionDesDecisions(warning, valueS, sensorId);
														}
														else if(warning->calculerDonneePrevisionelle(gm->getMesure(sensorId),attributeId, gm->getListeAttribut())){
															cout<<"WARNING!!! Votre capteur "<<sensorId<<" depassera le seuil de l'attribut "<<attributeId<<" dans 5 temps"<<endl;
															gestionDesDecisions(warning, valueS, sensorId);

														} else	warning->evaluerDecision(sensorId, valueS);

										}
									}
							}
						}
					}
				}
			}
