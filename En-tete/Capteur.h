/*************************************************************************
						   Catalogue  -  description
							 -------------------
	début                : 30/11/2018
	copyright            : (C) 2018 par YE Linda, YE Zihang
	e-mail               : linda.ye@insa-lyon.fr zihang.ye@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Catalogue> (fichier Catalogue.h)  ---------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;

class Capteur
{
public:
	// Constructeurs
	Capteur();
	Capteur(string sensorId, int longitude, int latitude, string description);

	//Accesseurs et mutateurs
	void setSensorId(string sensorId);
	void setLongitude(int longitude);
	void setDescription(string description);
	void setLattitude(int lattitude);
	int getLongitude() const;
	int getLattitude() const;
	string getSensorId() const;
	string getDescription() const;

	// Autres méthodes
	string caracteristiqueDeLair() const;

	void afficher() const;

private:
	string sensorId;
	int longitude;
	int latitude;
	string description;
};

#endif