#if ! defined ( Mesure_H )
#define Mesure_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdio.h>
#include <Time>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class analyser
{
	//----------------------------------------------------------------- PUBLIC

public:

	//-------------------------------------------- Constructeurs - destructeur
	Mesure( const Mesure & uneMesure );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Mesure(int timestamp, std::string sensorId, std::string attributeId, int value);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setTimestamp(Time newTimestamp) { this.timestamp = newTimestamp; }

	void setSensorId(int newSensorId) { this.sensorId = newSensorId; }

	void setAttributeId(int newattributeId) { this.attributeId = newAttributeId; }

	void setValue(int newvalue) { this.value = newValue; }

	Time getTimestamp() { return timestamp; }

	std::string getSensorId() { return sensorId; }

	std::string getAttributeId() { return attributeId; }

	int getValue ( ) { return value }

	Warning alerterSurMesure();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	Time timestamp;

	std::string sensorId;

	std::string attributeId;

	int value;

};

//-------------------------------- Autres définitions dépendantes de <analyser>

#endif // Mesure_H
