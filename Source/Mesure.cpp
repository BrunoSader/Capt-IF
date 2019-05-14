/*************************************************************************
analyser  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <analyser> (fichier Meusre.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type analyser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(const Mesure & uneMesure)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif

	this.timestamp = uneMesure.timestamp;

	this.sensorId = uneMesure.sensorId;

	this.attributeId = uneMesure.attributeId;

	this.value = uneMesure.value;

} //----- Fin de analyser (constructeur de copie)

Mesure::Mesure(time_t timestamp, string sensorId, string attributeId, int value)
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif

	this.timestamp = uneMesure.timestamp;

	this.sensorId = uneMesure.sensorId;

	this.attributeId = uneMesure.attributeId;

	this.value = uneMesure.value;
}

Mesure::Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de analyser

Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~analyser

Mesure::Warning alerterSurMesure()
{

}


  //------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

