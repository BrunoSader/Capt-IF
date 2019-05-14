#if ! defined ( Attribut_H )
#define Attribut_H

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

class analyser
{
	//----------------------------------------------------------------- PUBLIC

public:

	//-------------------------------------------- Constructeurs - destructeur
	Attribut(const Attribut & unAttribut);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Attribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Attribut(std::string attributeId, std::string unit, std::string description, int valeurSeuil);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Attribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setAttributeId(int newattributeId) { this.attributeId = newAttributeId; }

	void setUnit(int newUnit) { this.unit = newUnit; }

	void setDescription(int newDescription) { this.description = newDescription; }

	void setValeurSeuil(int newValeurSeuil) { this.valeurSeuil = newValeurSeuil; }

	std::string getAttributeId() { return attributeId; }

	std::string getUnit() { return unit; }

	std::string getDescription() { return description; }

	int getValeurSeuil() { return valeurSeuil;  }

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	std::string attributeId;

	std::string unit;

	std::string description;

	int valeurSeuil;

};

//-------------------------------- Autres d�finitions d�pendantes de <Attribut>

#endif // Attribut_H
#pragma once
