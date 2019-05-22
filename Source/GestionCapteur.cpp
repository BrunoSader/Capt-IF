/*************************************************************************
<<<<<<< HEAD
						   GestionCapteur  -  description
							 -------------------
	d�but                : 14/05/2019
	copyright            : (C) 2019 par GALL Roxane
	e-mail               : roxane.gall@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <GestionCapteur> ----------- ------------

#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionCapteur.h"
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

string GestionCapteur::afficherCapteur() const
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode afficherCapteur de <GestionCapteur>" << endl;
#endif
	
} //----- Fin de afficherCapteur

bool GestionCapteur::ajouterCapteur(Capteur c) 
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode ajouterCapteur de <GestionCapteur>" << endl;
#endif
	
	Capteur ajoute = Capteur(c);

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i].getSensorId == ajoute.getSensorId) {
			return false;
		}
	}

	listCapteur.push_back(ajoute); // ajout du capteur � la fin du vecteur

	// On ajoute le sensorId correspondant � la map dans GestionMesure
	// A FAIRE
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	return true;

} //----- Fin de ajouterCapteur

bool GestionCapteur::supprimerCapteur(Capteur c) 
// Algorithme :
// On supprime le capteur indiqu� de la liste des capteurs. Pour cela on parcours le vector contenant
// les capteurs et lorsqu'on trouve celui concern�, on le supprime.
// MAIS on ne supprime pas le sensorId de la map de GestionMesure car on doit toujours avoir acc�s 
// � ses anciennes mesures
{
#ifdef MAP
	cout << "Appel � la m�thode supprimerCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i] == c) {
			listCapteur.erase(listCapteur.begin() + i-1); // efface le i �me �l�ment
			return true;
		}
	}

	return false;

} //----- Fin de supprimerCapteur

bool GestionCapteur::surveillerCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode surveillerCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de surveillerCapteur

Capteur GestionCapteur::rechercherCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode rechercherCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (id.compare(listCapteur[i].getSensorId) == 0) { // si les sensorId sont identiques
			return listCapteur[i];
		}
	}

} //----- Fin de rechercherCapteur

Capteur GestionCapteur::rechercherCapteur(int latitude, int longitude) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode rechercherCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i].getLattitude == latitude && listCapteur[i].getLongitude == longitude) { // si les sensorId sont identiques
			return listCapteur[i];
		}
	}

} //----- Fin de rechercherCapteur

vector <Capteur> GestionCapteur::capteursSimilaires(string SensorId)
// Algorithme :
{
#ifdef MAP
	cout << "Appel � la m�thode capteursSimilaires de <GestionCapteur>" << endl;
#endif

} //----- Fin de capteursSimilaires

//------------------------------------------------- Surcharge d'op�rateurs

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
=======
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
>>>>>>> 53a0ae5d333d37c659bbae42608dbb316434e22e
