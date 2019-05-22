/*************************************************************************
analyser  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <analyser> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Attribut.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type analyser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & unAttribut)
{
	this->attributeId = unAttribut.attributeId;

	this->unit = unAttribut.unit;

	this->description = unAttribut.description;

	this->valeurSeuil = unAttribut.valeurSeuil;
// Mode d'emploi (constructeur de copie) :
//
// Contrat :
//
}

Attribut::Attribut() {}
// Mode d'emploi :
//
// Contrat :
//

Attribut::Attribut(string attributeId, string unit, string description, int valeurSeuil)
{
	this->attributeId = attributeId;

	this->unit = unit;

	this->description = description;

	this->valeurSeuil = valeurSeuil;
}
// Mode d'emploi :
//
// Contrat :
//

Attribut::~Attribut() {}
// Mode d'emploi :
//
// Contrat :
//


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
