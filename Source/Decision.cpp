/*************************************************************************
analyser  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <analyser> (fichier Decision.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Decision.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type analyser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
	Decision::Decision(const Decision & uneDecision)
	{
		this->texte = uneDecision.texte;

		this->note = uneDecision.note;
	}
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Decision::Decision() {}
	// Mode d'emploi :
	//
	// Contrat :
	//

	Decision::Decision(string texte, int note)
	{
		this->texte = texte;

		this->note = note;
	}
	// Mode d'emploi :
	//
	// Contrat :
	//

	Decision::~Decision() {}
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------------------------ PRIVE

	//----------------------------------------------------- Méthodes protégées

