/*************************************************************************
analyser  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <analyser> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribut.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type analyser::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & unAttribut)
{
	this.attributeId = unAttribut.attributeId;

	this.unit = unAttribut.unit;

	this.description = unAttribut.description;

	this.valeurSeuil = unAttribut.valeurSeuil;
// Mode d'emploi (constructeur de copie) :
//
// Contrat :
//

Attribut::Attribut() {}
// Mode d'emploi :
//
// Contrat :
//

Attribut::Attribut(std::string attributeId, std::string unit, std::string description, int valeurSeuil)
{
	this.attributeId = attributeId;

	this.unit = unit;

	this.description = description;

	this.valeurSeuil = valeurSeuil;
	}
// Mode d'emploi :
//
// Contrat :
//

virtual Attribut::~Attribut() {}
// Mode d'emploi :
//
// Contrat :
//


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

