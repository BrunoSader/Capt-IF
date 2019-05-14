#if ! defined ( Attribut_H )
#define Attribut_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdio.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
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
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	std::string attributeId;

	std::string unit;

	std::string description;

	int valeurSeuil;

};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // Attribut_H
