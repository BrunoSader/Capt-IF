/*************************************************************************
                           Warning  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Warning> (fichier Warning.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../En-tete/Warning.h"
#include <ctime>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
int Warning::calculerDonneePrevisionelle (string sensorID, map<string,map<time_t,map<string,int>>> listeMesurebyCapteur, Attribut lAttribut)
// Algorithme :
//
{
	map<string,map<time_t,map<string,int>>>::iterator sensor_it;
	sensor_it = listeMesurebyCapteur.find(sensorID);
	//On trouve notre capteur dans la liste

	map<time_t,map<string,int>> listeMesurebyDate = sensor_it->second;
	map<time_t,map<string,int>>::reverse_iterator date_it;
	map<string,int>::iterator attribut_it;
	int* values = new int [5];
	int cpt=0;
	for (date_it=listeMesurebyDate.rbegin(); date_it!=listeMesurebyDate.rend(); ++date_it)
	{
		attribut_it = date_it->second.find(lAttribut.getAttributeId());
		values[cpt] = attribut_it->second;
		cpt++;
	}
	int difference = (values[0]-values[1])*0.5 + (values[1]-values[2])*0.25 + (values[2]-values[3])*0.15 + (values[3]-values[4])*0.1;
	return (values[0]*difference);
}
 //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
Warning & Warning::operator = ( const Warning & unWarning )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Warning::Warning ( const Warning & unWarning )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Warning>" << endl;
#endif
} //----- Fin de Warning (constructeur de copie)


Warning::Warning (int type, string attributID)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Warning>" << endl;
#endif
	this->type = type;
	this->attributID = attributID;
} //----- Fin de Warning


Warning::~Warning ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Warning>" << endl;
#endif
} //----- Fin de ~Warning


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
