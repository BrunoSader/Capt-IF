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
  Capteur(string sensorId, int longitude, int lattitude, string description);

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
  int lattitude;
  string description;
};

#endif