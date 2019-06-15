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


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques



//------------------------------------------------- Surcharge d'op�rateurs

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
	else  return true;
}

bool operator > (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year > tm2.tm_year){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon > tm2.tm_mon){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday > tm2.tm_mday){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour > tm2.tm_hour){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min > tm2.tm_min){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min && tm1.tm_sec > tm2.tm_sec){return true;}
	else
	return false;
}

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

string GestionMesure::consulterMesure(map<string, map<struct tm, map<string,double>>> mesures)
{
    string res;

    // Cas où la map comporte des NULL / n'est pas remplie, affichage erreur
    if (mesures.empty()) {
        res += " Aucun résultat correspondant à votre recherche n'a été trouvé ";
    }

    // Cas où la map est valide, affichage
   for(map<string, map<struct tm, map<string,double>>>::iterator i=mesures.begin(); i!=mesures.end(); ++i) {
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

/* Renvoie */
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
				if(it3->first.tm_mday+1 == tm.tm_mday+1 && it3->first.tm_mon+1 == tm.tm_mon+1 && it3->first.tm_hour == tm.tm_hour && it3->first.tm_year == tm.tm_year && it3->first.tm_min == tm.tm_min && it3->first.tm_sec == tm.tm_sec){
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

map<string,double> GestionMesure::getMesureAttribute(map<struct tm, map<string,double>>::iterator i2, bool * bitTab, string * arg) {

    map<string,double> result;

    map<string,double>::iterator i3;

    if (bitTab[4]) {
        for(map<string,double>::iterator i3=i2->second.begin(); i3!=i2->second.end(); ++i3) { // parcours 3eme map
            if (!i3->first.compare(arg[6]) && i3!=i2->second.end()) {
                result.insert(make_pair(i3->first,i3->second));
            }
            else {
                result.clear();
            }
        }
    }
    else {
        for(map<string,double>::iterator i3=i2->second.begin(); i3!=i2->second.end(); ++i3) { // parcours 3eme map
            result.insert(make_pair(i3->first,i3->second));
        }
    }

    return result;
}

map<struct tm, map<string,double>>  GestionMesure::getMesureDate (map<string, map<struct tm, map<string,double>>>::iterator i, bool * bitTab, string * arg) {

    map<struct tm, map<string,double>> result;

    if (bitTab[3]) {
        struct tm t1;
        t1.tm_year=stoi(arg[0]);
        t1.tm_mon=stoi(arg[1]);
        t1.tm_mday=stoi(arg[2]);

        struct tm t2;
        t2.tm_year=stoi(arg[3]);
        t2.tm_mon=stoi(arg[4]);
        t2.tm_mday=stoi(arg[5]);

        for(map<struct tm, map<string,double>>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2) { //parcours 2eme map
            if(i2->first < t2 && i2->first > t1){
                map<string,double> resultAtt = getMesureAttribute(i2,bitTab,arg);
                if (!resultAtt.empty()) {
                    result.insert(make_pair(i2->first,resultAtt)); //make pair
                }
                else {
                    result.clear();
                }
            }
        }
    } else {

        for(map<struct tm, map<string,double>>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2) { //parcours 2eme map
            map<string,double> resultAtt = getMesureAttribute(i2,bitTab,arg);
            if (!resultAtt.empty()) {
                result.insert(make_pair(i2->first,getMesureAttribute(i2,bitTab,arg)));
            }
        }
    }

    return result;
}

map<string, map<struct tm, map<string,double>>> GestionMesure::getMesureCapteur (bool * bitTab, string * arg, string sensorId) {

    map<string, map<struct tm, map<string,double>>> result;

    map<string, map<struct tm, map<string,double>>>::iterator i; //Premier itérateur sur la map

    if (!sensorId.empty()) {
        i = listeMesure.find(sensorId);
        if (i!=listeMesure.end()) {
            map<struct tm, map<string,double>> resultDate = getMesureDate(i,bitTab,arg);
            if (!resultDate.empty()) {
                result.insert(make_pair(sensorId,resultDate));
            }
        }
    }
    else {
        for(i=listeMesure.begin(); i!=listeMesure.end(); ++i) { //parours de tous les sensorId / 1ere map
            map<struct tm, map<string,double>> resultDate = getMesureDate(i,bitTab,arg);
            if (!resultDate.empty()) {
                result.insert(make_pair(i->first,getMesureDate(i,bitTab,arg))); //make pair
            }
        }
    }
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
	if(moyenneCapteur1 == -10 && moyenneCapteur2 == -10) return true;
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
