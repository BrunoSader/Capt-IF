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
#include <stdlib.h>
#include <math.h>

//------------------------------------------------------ Include personnel
#include "../En-tete/GestionMesure.h"

bool operator == (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min) return true;
	else return false;
}

bool operator < (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year < tm2.tm_year){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon < tm2.tm_mon){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday < tm2.tm_mday){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour < tm2.tm_hour){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min < tm2.tm_min){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min && tm1.tm_sec < tm2.tm_sec){return true;}
	else return false;
}
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type GestionMesure::M�thode ( liste de param�tres )
// Algorithme :
//




//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
GestionMesure::GestionMesure ( const GestionMesure & unGestionMesure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionMesure>" << endl;
#endif
} //----- Fin de GestionMesure (constructeur de copie)


GestionMesure::GestionMesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionMesure>" << endl;
#endif
} //----- Fin de GestionMesure


GestionMesure::~GestionMesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionMesure>" << endl;
#endif
} //----- Fin de ~GestionMesure

string GestionMesure::consulterType( )
{
    string res;
    for(unsigned int i=0; i<listeTypeMesure.size(); ++i)
    {
        res += listeTypeMesure[i].getDescription();
        res += "\n";
    }
    return res;
}

string GestionMesure::consulterMesure( )
{
    string res;
   for(map<string, map<struct tm, map<string,double>>>::iterator i=listeMesure.begin(); i!=listeMesure.end(); ++i) {
        res += "SensorId : " + i->first ;
        res += "\n";
        for(map<struct tm, map<string,double>>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2) {
	    res += "	Date : \n";
	    res += "	" + to_string(i2->first.tm_mday) + "/";
	    res += to_string(i2->first.tm_mon) + "/";
	    res += to_string(i2->first.tm_year) + "\n	Heure \n";
	    res += "	" + to_string(i2->first.tm_hour) + ":";
	    res += to_string(i2->first.tm_min) + ":";
	    res += to_string(i2->first.tm_sec) ;
            res += "\n";
             for(map<string,double>::iterator i3=i2->second.begin(); i3!=i2->second.end(); ++i3) {
                  res += "		Attribut : 	" + i3->first  + "\n";
		  res += "		Valeur : 	"+ to_string(i3->second);
                  res += "\n";
             }
        }
    }
    return res;
}


map<struct tm, map<string,double>> GestionMesure::getMesure(string id)
{
    map<struct tm, map<string,double>> res;
    map<string, map<struct tm, map<string,double>>>::iterator i=listeMesure.find(id);
    if(i != listeMesure.end()) return i->second;
    return res;
}



struct tab GestionMesure::moyenneValAttribut(string attributId, string sensorId)
{
    map<struct tm, map<string,double>> valeur = getMesure(sensorId);
    double somme = 0;
    double nombre = 0;
    struct tab res;
		double borneInf = 1000;
		double borneSup = 0;
		res.moyenne = -10;
		res.etendue = -10;
    if(!valeur.empty()){
				for(map<struct tm, map<string,double>>::iterator i = valeur.begin(); i != valeur.end(); i++){
						map<string,double> :: iterator i2 = i->second.find(attributId);
						somme += i2->second;
						if(i2->second > borneSup) borneSup = i2->second;
						if(i2->second < borneInf) borneInf = i2->second;
						nombre++;
					}
				 if(nombre == 0) nombre = 1;
				 if(somme/nombre == 0 )res.moyenne = -10;
			 	 else res.moyenne = somme/nombre;
			 	 res.etendue = borneSup-borneInf;
   }
   cout<<"pour le capteur "<<sensorId<< " avec l'attribut "<<attributId<<" la moyenne est "<< somme<<" " <<nombre<<" et l'étendue est "<<res.etendue<<endl;
   return res;
}

double GestionMesure::ecartType(string attributId, string sensorId, double moyenne)
{
    map<struct tm, map<string,double>> valeur = getMesure(sensorId);
    double somme = 0;
    double nombre = 0;
    double res = -10;
    if(valeur.empty()) res = -10;
    else{
				for(map<struct tm, map<string,double>>::iterator i = valeur.begin(); i != valeur.end(); i++){
					map<string,double> :: iterator i2 = i->second.find(attributId);
					somme += (i2->second - moyenne)*(i2->second - moyenne);
					nombre++;
				}
				res = sqrt(somme/nombre);
   }
   return res;
}

void GestionMesure::ajouterAttribut(string id, string unite, string description)
{
	listeTypeMesure.push_back(Attribut(id, unite, description, 0));
}


void GestionMesure::ajouterAttribut(string id, string unite, string description, int seuil)
{
	listeTypeMesure.push_back(Attribut(id, unite, description, seuil));
}

void GestionMesure::ajouterMesure(struct tm tm, string sensorId, string attributeId, double value)
{
	//map<string, map<time_t, map<string,double>>> listeMesure;

	/*SensorId
	Date
	AttributeId
	Valeure*/
	map<string, map<struct tm, map<string,double>>>::iterator it = listeMesure.find(sensorId);
		if(it == listeMesure.end()){
			map<string, double> mp;
			mp.insert(make_pair(attributeId, value));
			map<struct tm, map<string,double>> mp2;
			mp2.insert(make_pair(tm, mp));
			listeMesure.insert(make_pair(sensorId, mp2));
		} else{
			map<struct tm, map<string,double>>::iterator it2 = it->second.end();
			//recodage de .find
			 for(map<struct tm, map<string,double>>::iterator it3=it->second.begin(); it3!=it->second.end(); ++it3) {
				if(it3->first.tm_mday+1 == tm.tm_mday+1 && it3->first.tm_mon+1 == tm.tm_mon+1 && it3->first.tm_hour == tm.tm_hour){
					it2 = it3;
					break;
				}
			}

			if(it2 == it->second.end()){
				map<string, double> mp2;
				mp2.insert(make_pair(attributeId, value));
				it->second.insert(make_pair(tm, mp2));
			}else{

				it2->second.insert(make_pair(attributeId, value));
			}
		}



}

vector<Attribut> GestionMesure::getListeAttribut(){
	return listeTypeMesure;
}

bool GestionMesure::capteurProches(string idCapteur1, string idCapteur2, double certitude, string attribut){
	//on prend chaque jour et on reccupère toutes les valeurs des capteurs sur les 2 capteurs
	//Capteur1 est la référence
	struct tab tabc1 = moyenneValAttribut(attribut, idCapteur1);
	struct tab tabc2 = moyenneValAttribut(attribut, idCapteur2);
	double etendueCapteur1 =  tabc1.etendue;
	double etendueCapteur2 =  tabc2.etendue;
	double moyenneCapteur1 = tabc1.moyenne;
	double moyenneCapteur2 = tabc2.moyenne;
	double ecartTypeCapteur1 = ecartType(attribut, idCapteur1, moyenneCapteur1);
	double ecartTypeCapteur2 = ecartType(attribut, idCapteur2, moyenneCapteur2);
	double borneInf = moyenneCapteur1 - moyenneCapteur1*(1-certitude);
	double borneSup = moyenneCapteur1 + moyenneCapteur1*(1-certitude);

	bool res = true;
	if((moyenneCapteur1 == -10 && moyenneCapteur2 != -10) || (moyenneCapteur1 != -10 && moyenneCapteur2 == -10)) res = false;
	if(moyenneCapteur2 > borneSup || moyenneCapteur2 < borneInf) res = false;
	borneInf = ecartTypeCapteur1 - ecartTypeCapteur1*(1-certitude);
	borneSup = ecartTypeCapteur1 + ecartTypeCapteur1*(1-certitude);
	if(ecartTypeCapteur2 > borneSup || ecartTypeCapteur2 < borneInf) res = false;
	borneInf = etendueCapteur1 - etendueCapteur1*(1-certitude);
	borneSup = etendueCapteur1 + etendueCapteur1*(1-certitude);
	if(etendueCapteur2 > borneSup || etendueCapteur2 < borneInf) res = false;
	return res;
}

/* vector <Mesure> GestionMesure::getMesureCapteur (bool * bitTab, vector<string> arg) {

    vector<Mesure> result;
    int i = 0;

    string sensorId = "";
    float longitudeMin;
    float latitudeMin;
    float longitudeMax;
    float latitudeMax;
    struct tm debut;
    struct tm fin;
    string attributeId;


    switch (i) {

        case 0 : //sensorID

            if(bitTab[0]) {
                sensorId = arg[0];
                i += 2; // on augmente i de 2 car on ne regarde pas le case 1, impossible puisque le capteur est caractérisé par son ID
            }
            else {
                i++;
            }
            break;

        case 1 : // coordonnées

            if(bitTab[1]) {
                latitudeMin = strtof(arg[1].c_str(),nullptr);
                longitudeMin = strtof(arg[2].c_str(),nullptr);
                latitudeMax = strtof(arg[3].c_str(),nullptr);
                longitudeMax = strtof(arg[4].c_str(),nullptr);
            }
            i++;

            break;

        case 2 : // dates

            if(bitTab[2]) {
                //debut = arg[5];
                //fin = arg[6];
            }


            break;

        case 3 : // attributeId


            if(bitTab[2]) {
                attributeId = arg[7];
            }
            break;

    }


    return result;
}
*/

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
