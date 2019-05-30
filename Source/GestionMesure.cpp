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
#include "../En-tete/GestionMesure.h"


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

bool operator == (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min) return true;
	else return false;
}

bool operator < (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year < tm2.tm_year || tm1.tm_mon < tm2.tm_mon || tm1.tm_mday < tm2.tm_mday || tm1.tm_hour < tm2.tm_hour || tm1.tm_min < tm2.tm_min) return true;
	else return false;
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

string GestionMesure::consulterMesure( )
{
    string res;
   for(map<string, map<struct tm, map<string,double>>>::iterator i=listeMesure.begin(); i!=listeMesure.end(); ++i) {
        res += "SensorId : " + i->first ;
        res += "\n";
        for(map<struct tm, map<string,double>>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2) {
	    res += "	Date : \n";
	    res += "	" + to_string(i2->first.tm_mday+1) + "/";
	    res += to_string(i2->first.tm_mon+1) + "/";
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


vector<Mesure> GestionMesure::getMesure(time_t laDate)
{
    vector <Mesure> res;
      /*  for(map<string, map<time_t, map<string,int>>>::iterator i=listeMesure.begin(); i!=listeMesure.end(); ++i) {
             map<time_t, map<string,int>>::iterator it;
        	it = i->second.find(laDate);
        	if (it != i->second.end())
	           {
	               for(map<string,int>::iterator i3=it->second.begin(); i3!=it->second.end(); ++i3) {
                  res += i3->first ;
                  res += "\n";
             }
	            }*/
    return res;
}


int GestionMesure::moyenneValAttribut(Attribut at)
{
    return 0;
}

void GestionMesure::ajouterAttribut(string id, string unite, string description)
{
	listeTypeMesure.push_back(Attribut(id, unite, description, 0)); 
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
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
