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
    struct tm tm;
    map<string, double> res2;
    res2.insert(make_pair(" ", 0.0));
    res.insert(make_pair(tm, res2));
    map<string, map<struct tm, map<string,double>>>::iterator i=listeMesure.find(id);
    if(i != listeMesure.end()) return i->second;
    return res;
}



double GestionMesure::moyenneValAttribut(string attributId, string sensorId)
{
    map<struct tm, map<string,double>> valeur = getMesure(sensorId);
    double somme = 0;
    double nombre = 0;
    double res = 0;
    if(valeur.empty()) res = -10;
    else{
	for(map<struct tm, map<string,double>>::iterator i = valeur.begin(); i != valeur.end(); i++){
		map<string,double> :: iterator i2 = i->second.find(attributId);
		somme += i2->second;
		nombre++;
	}
   }
   res = somme/nombre;
   if(res == 0) res = -10;
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
