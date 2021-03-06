/*************************************************************************
                           GestionMesure  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <GestionMesure> (fichier GestionMesure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../En-tete/Capteur.h"
#include "../En-tete/GestionCapteur.h"
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"
#include <math.h>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type GestionMesure::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode




//------------------------------------------------- Surcharge d'op�rateurs
/*GestionCapteur & GestionCapteur::operator = ( const GestionCapteur & unGestionCapteur )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
GestionCapteur::GestionCapteur ( const GestionCapteur & unGestionCapteur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionCapteur>" << endl;
#endif
} //----- Fin de GestionCapteur (constructeur de copie)


GestionCapteur::GestionCapteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionCapteur>" << endl;
#endif
} //----- Fin de GestionMesure


GestionCapteur::~GestionCapteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionCapteur>" << endl;
#endif
} //----- Fin de ~GestionMesure

string GestionCapteur::afficherCapteur( )
{
    string res;
    for(unsigned int i=0; i<listeCapteur.size(); ++i)
    {
        res += listeCapteur[i].getSensorId() + "	";
	res += to_string(listeCapteur[i].getLattitude());
	res += "		";
	res += to_string(listeCapteur[i].getLongitude());
        res += "\n";
    }
    return res;
}

void GestionCapteur::ajouterCapteur(string id, double lattitude, double longitude, string description )
{
	listeCapteur.push_back(Capteur(id, lattitude, longitude, description));
}

void GestionCapteur::ajouterCapteur(double lattitude, double longitude, string description )
{
  bool nomCorrect = false;
  int taille = listeCapteur.size();
  while(!nomCorrect){
	   string id = "Sensor" + to_string(taille++);
     if(rechercherCapteur(id).getSensorId() == "null"){
	      listeCapteur.push_back(Capteur(id, lattitude, longitude, description));
        nomCorrect = true;
      }
  }
}


bool GestionCapteur::supprimerCapteur(int choix, double lattitude, double longitude, string id)
{
	Capteur c;
	if(choix == 1) c = rechercherCapteur(lattitude, longitude);
	if(choix == 2) c = rechercherCapteur(id);
	bool supp = false;
	deque<Capteur> :: iterator it;

	for(it = listeCapteur.begin(); it != listeCapteur.end(); it++){
		if(it->getSensorId() == c.getSensorId()){
			listeCapteur.erase(it);
			supp = true;
		}
	}
	return supp;
}

bool GestionCapteur::surveillerCapteur(int choix, double lattitude, double longitude, string id, GestionMesure* gm)
{
  bool res = true;
	Capteur c;
	if(choix == 1){
		c = rechercherCapteur(lattitude, longitude);
		id = c.getSensorId();
	}
	map<struct tm, map<string,double>> valeur = gm->getMesure(id);
	if(valeur.empty()) return false;
	else{
    /*On vérifie d'abord si les valeurs ne sont pas extrêmes
	03 entre 0 et 300
	S02 entre 0 et 600
	NO2 entre 0 et 500
	PM10 entre 0 et 200*/
	for(map<struct tm, map<string,double>>::iterator i=valeur.begin(); i!=valeur.end(); ++i) {
		for(map<string,double>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2){
			if(i2->first == "O3" && (i2->second > 300 || i2->second < 0)) res = false;
			if(i2->first == "SO2" && (i2->second > 600 || i2->second < 0)) res = false;
			if(i2->first == "NO2" && (i2->second > 500 || i2->second < 0)) res = false;
			if(i2->first == "PM10" && (i2->second > 200 || i2->second < 0)) res = false;
		}
	}

    /*Puis si le Capteur a fait au moins un relevé par jour. Sur la dernière semaine*/
	map<struct tm, map<string,double>> :: iterator i = valeur.end();

	i--;
	int jour = i->first.tm_mday ;
	int compteur = 0;
	 for(i = valeur.end(); i != valeur.begin(); i--){
		if(compteur == 7) break;
		if(i->first.tm_mday == jour) {
			jour = jour - 1;
			compteur ++;
		}
    if(jour <= 0) jour = 30;
	}
	if(compteur < 7) res = false;
	}

	return res;
}

Capteur GestionCapteur::rechercherCapteur(string id)
{
	Capteur c ("null", 0, 0, "null");
	for(uint i = 0; i < listeCapteur.size(); i++){
		if(listeCapteur[i].getSensorId() == id){
			return listeCapteur[i];
		}
	}
	return c;
}


Capteur GestionCapteur::rechercherCapteur(double lattitude, double longitude )
{
	Capteur c;
	int indice = __INT_MAX__;

	for(uint i = 0; i < listeCapteur.size(); i++){
		if(listeCapteur[i].getLattitude() == lattitude && listeCapteur[i].getLongitude() == longitude){
			return listeCapteur[i];
		} else if(indice > ( sqrt((listeCapteur[i].getLattitude() - lattitude)*(listeCapteur[i].getLattitude() - lattitude) + (listeCapteur[i].getLongitude() - longitude)*(listeCapteur[i].getLongitude() - longitude)))){
			indice = sqrt((listeCapteur[i].getLattitude() - lattitude)*(listeCapteur[i].getLattitude() - lattitude) + (listeCapteur[i].getLongitude() - longitude)*(listeCapteur[i].getLongitude() - longitude));
			c = listeCapteur[i];
		}
	}
	return c;
}

vector<Capteur> GestionCapteur::rechercherCapteurParIntervalle(float latitude, float latitudeMax, float longitude, float longitudeMax) {
  	vector<Capteur> c;
	int indice = __INT_MAX__;
    bool capteurDansZone = false;
	for(uint i = 0; i < listeCapteur.size(); i++){
		if(((listeCapteur[i].getLattitude() > latitude && listeCapteur[i].getLattitude() < latitudeMax) // cas classique latMin < latMax
            || (listeCapteur[i].getLattitude() > latitude && listeCapteur[i].getLattitude() < 90) || (listeCapteur[i].getLattitude() > -90 && listeCapteur[i].getLattitude() < latitudeMax))
            && ((listeCapteur[i].getLongitude() > longitude && listeCapteur[i].getLongitude() < longitudeMax)
            || (listeCapteur[i].getLongitude() > longitude && listeCapteur[i].getLongitude() < 180) || (listeCapteur[i].getLongitude() > -180 && listeCapteur[i].getLongitude() < longitudeMax))){

			c.push_back(listeCapteur[i]);
		}
    }

    return c;
}

string GestionCapteur::capteursSimilaires(int choix, double lattitude, double longitude, string id, GestionMesure* gm, double confiance)
{

	string res = "";
  string res2 = "";
	Capteur ca;
	Capteur comp;
	int size = gm->getListeAttribut().size();
	bool similaire = true;
	if(choix == 1){
		ca = rechercherCapteur(lattitude, longitude);
		id = ca.getSensorId();
	}
  ca = rechercherCapteur(id);
	//On vérifie si le capteur a bien des mesures renseignées et qu'il existe
	if(gm->getMesure(id).empty() || ca.getSensorId() == "null") {
		res = "Le Capteur renseigné n'a pas de mesures ou n'existe pas, et donc pas de capteur similaire";
		return res;
	}  else{
 
    for(uint i = 0; i < listeCapteur.size(); i++){
      similaire = true;
      if (id != listeCapteur[i].getSensorId()){
        	   for(int j = 0; j < size; j++){
        			    if(!gm->capteurProches(id, listeCapteur[i].getSensorId(), confiance,  gm->getListeAttribut()[j].getAttributeId()))
                  {
                    res2 += "     pour l'attribut " +gm->getListeAttribut()[j].getAttributeId()+"\n";
                    similaire = false;
                  }
             }
             if(similaire == true) res += "Le capteur " + listeCapteur[i].getSensorId() + " est similaire au capteur que vous avez demandé\n";
             else res += "Le capteur " + listeCapteur[i].getSensorId() + " n'est pas similaire au capteur que vous avez demandé\n" + res2;
             res2 = "";
           }
     }
   }
	return res;
}
