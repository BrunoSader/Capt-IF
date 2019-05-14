/*************************************************************************
analyser  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <analyser> (fichier Meusre.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type analyser::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

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

Mesure::Mesure(Time timestamp, std::string sensorId, std::string attributeId, int value)
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

//----------------------------------------------------- M�thodes prot�g�es

