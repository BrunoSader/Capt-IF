#if ! defined ( Decision_H )
#define Decision_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdio.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
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

	void setTexte(int newTexte) { this.texte = newTexte; }

	void setNote(int newNote) { this.note = newNote; }

	std::string getTexte() { return texte; }

	int getNote() { return note; }

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	std::string texte;

	int note;

};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // Attribut_H
#pragma once
