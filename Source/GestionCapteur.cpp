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

void GestionCapteur::ajouterCapteur(string id, int lattitude, int longitude, string description )
{ 
	listeCapteur.push_back(Capteur(id, lattitude, longitude, description)); 
	//L'ajouter aussi dans le fichier qu'on nous fourni ?
}

void GestionCapteur::ajouterCapteur(int lattitude, int longitude, string description )
{ 
	string id = "Sensor" + to_string(listeCapteur.size());
	listeCapteur.push_back(Capteur(id, lattitude, longitude, description)); 
}


bool GestionCapteur::supprimerCapteur(int choix, int lattitude, int longitude, string id)
{
	Capteur c;
	if(choix == 1) c = rechercherCapteur(lattitude, longitude);
	if(choix == 2) c = rechercherCapteur(id);
	bool supp = false;	
	int compte = 0;
	deque<Capteur> :: iterator it;
    	
	for(it = listeCapteur.begin(); it != listeCapteur.end(); it++){
		if(listeCapteur[compte].getSensorId() == c.getSensorId()){
			listeCapteur.erase(it);
			supp = true;
		}
		compte++;
	}
	return supp;
}


bool GestionCapteur::surveillerCapteur(int choix, int lattitude, int longitude, string id, GestionMesure* gm)
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
	}
	if(compteur < 7) res = false;	
	}	

	return res;
}

Capteur GestionCapteur::rechercherCapteur(string id )
{
	Capteur c;
	for(uint i = 0; i < listeCapteur.size(); i++){
		if(listeCapteur[i].getSensorId() == id){
			return listeCapteur[i];
		}
	}
	return c;
}

Capteur GestionCapteur::rechercherCapteur(int lattitude, int longitude )
{
	Capteur c;
	int indice = 1000;
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

string GestionCapteur::capteursSimilaires(int choix, int lattitude, int longitude, string id, GestionMesure* gm, double confiance)
{ 
	//Possible de faire bien mieux avec un intervalle de confiance et tout !!
	//Obligé de changer la manière de vérifier car pour l'instant toutes les moyennes sont vraiment très proches ce n'est pas un bon moyen de comparaison.
	string res = "";
	Capteur ca; 
	Capteur comp;
	int size = gm->getListeAttribut().size() -1;
	double tabref [size];
	double valeurComp = 0;
	bool similaire = true;
	if(choix == 1){
		ca = rechercherCapteur(lattitude, longitude); 
		id = ca.getSensorId();
	} 
	//On vérifie si le capteur a bien des mesures renseignées
	if(gm->getMesure(id).empty()) {
		res = "Le Capteur renseigné n'a pas de mesures, et donc pas de capteur similaire"; 
		return res;
	}  else{
		//on calcule les moyennes pour chaque attribut
		for(int i = 0; i < size; i++){
			tabref[i] = gm->moyenneValAttribut(gm->getListeAttribut()[i].getAttributeId(), id);
			cout<<"tabref"<<i<<" = "<<tabref[i]<<endl;
		} 
		for(uint i = 0; i < listeCapteur.size() -1; i++){
			similaire = true;
			comp = listeCapteur[i];
			//On va regarder pour chaque capteur si il convient
			if(listeCapteur[i].getSensorId() != id){ 
				//le -1 est censé être enlevé, il est la à cause d'erreur à la lecture du fichier
				//Pour chaque attribut on calucle sa moyenne et on compare avec celle de la référence
				for(uint i2 = 0; i2 < gm->getListeAttribut().size() -1; i2++){
					if(similaire == true){
						valeurComp = gm->moyenneValAttribut(gm->getListeAttribut()[i2].getAttributeId(), comp.getSensorId());
						if(valeurComp > tabref[i2] && (tabref[i2]/valeurComp) < confiance) similaire = false;
						if(valeurComp < tabref[i2] && (valeurComp/tabref[i2]) < confiance) similaire = false; 
					cout<<"Pour l'attribut "<< gm->getListeAttribut()[i2].getAttributeId() <<" avec le capteur "<<comp.getSensorId() << " similaire vaut "<<similaire<<" les valeurs comparées sont "<< valeurComp<<" "<<" et "<<tabref[i2]<<endl;
					cout<<(valeurComp > tabref[i2]) <<" " << (tabref[i2]/valeurComp)<<" " <<((tabref[i2]/valeurComp) < confiance) << " "<<confiance<<endl;
					}
				} 
			if(similaire == false) res += "Le capteur " + comp.getSensorId() + " n'est pas similaire au capteur que vous avez demandé" + "\n";
			else res += "Le capteur " + comp.getSensorId() + " est similaire au capteur que vous avez demandé" +"\n";
				
			}
			
		}
	}
				
	return res;
}
