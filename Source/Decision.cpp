/*************************************************************************
analyser  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <analyser> (fichier Decision.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Decision.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type analyser::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
	Decision::Decision(const Decision & uneDecision)
	{
		this->action = uneDecision.action;

		this->note = uneDecision.note;
	}
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Decision::Decision(bool *action, int note)
	{
		this->action = action;
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

	//----------------------------------------------------- M�thodes prot�g�es
