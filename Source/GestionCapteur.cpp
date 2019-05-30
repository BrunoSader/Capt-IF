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


bool GestionCapteur::supprimerCapteur(Capteur c )
{
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


bool GestionCapteur::surveillerCapteur(string id )
{
    	bool res = true;
/*On vérifie d'abord si les valeurs ne sont pas extrêmes 
	03 entre 0 et 300
	S02 entre 0 et 600
	NO2 entre 0 et 500
	PM10 entre 0 et 200*/
	

/*Puis si le Capteur a fait au moins un relevé par jour. Sur la dernière semaine*/
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

deque<Capteur> GestionCapteur::capteursSimilaires(string id )
{
	/*code ici*/
	deque<Capteur> c;
	return c;
}
