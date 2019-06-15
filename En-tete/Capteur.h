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
  Capteur(string sensorId, float longitude, float lattitude, string description);

  //Accesseurs et mutateurs
  void setSensorId(string sensorId);
  void setLongitude(float longitude);
  void setDescription(string description);
  void setLattitude(float lattitude);
  float getLongitude() const;
  float getLattitude() const;
  string getSensorId() const;
  string getDescription() const;

  // Autres méthodes
  string caracteristiqueDeLair() const;

  void afficher() const;

private: 
  string sensorId;
  float longitude;
  float lattitude;
  string description;
};

#endif
