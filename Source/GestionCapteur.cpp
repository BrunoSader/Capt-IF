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
#include "GestionCapteur.h"

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
        res += listeCapteur[i].getSensorId();
        res += "\n";
    }
    return res;
}

void GestionCapteur::ajouterCapteur(string id, int lattitude, int longitude, string description )
{ 
	listeCapteur.push_back(Capteur(id, lattitude, longitude, description)); 
}


bool GestionCapteur::supprimerCapteur(Capteur c )
{
    	/*bool res = listeCapteur.erase(c);
	return res;*/
	return true;
}


bool GestionCapteur::surveillerCapteur(string id )
{
    	bool res = true;
/*code ici*/
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

vector<Capteur> GestionCapteur::capteursSimilaires(string id )
{
	/*code ici*/
	vector<Capteur> c;
	return c;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
