#if ! defined ( Decision_H )
#define Decision_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <stdio.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Decision
{
	//----------------------------------------------------------------- PUBLIC

public:

	//-------------------------------------------- Constructeurs - destructeur
	Decision(const Decision & uneDecision);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Decision();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Decision(std::string texte, int note);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Decision();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setTexte(int newTexte) { this->texte = newTexte; }

	void setNote(int newNote) { this->note = newNote; }

	std::string getTexte() { return texte; }

	int getNote() { return note; }

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	std::string texte;

	int note;

};

//-------------------------------- Autres d�finitions d�pendantes de <Attribut>

#endif // Attribut_H
#pragma once
