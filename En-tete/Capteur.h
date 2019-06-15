#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <iostream>
#include <string>
using namespace std;

class Capteur
{
public:
  // Constructeurs
  Capteur();
  Capteur(string sensorId, double longitude, double lattitude, string description);

  //Accesseurs et mutateurs
  void setSensorId(string sensorId);
  void setLongitude(double longitude);
  void setDescription(string description);
  void setLattitude(double lattitude);
  double getLongitude() const;
  double getLattitude() const;
  string getSensorId() const;
  string getDescription() const;

  // Autres méthodes
  string caracteristiqueDeLair() const;

  void afficher() const;

private: 
  string sensorId;
  double longitude;
  double lattitude;
  string description;
};

#endif
