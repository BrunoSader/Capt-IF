#include "Capteur.h"

#include <cmath>
#include <iostream>
#include<string>
using namespace std;

Capteur::Capteur() : sensorId(" "), longitude(-1000), latitude(-1000), description(" ")
{

}

Capteur::Capteur(string sensorId, int longitude, int lattitude, string description) : sensorId(sensorId), longitude(longitude), latitude(lattitude), description(description)
{

}

Capteur::Capteur(const Capteur & captACopier) : sensorId(captACopier.sensorId), longitude(captACopier.longitude), latitude(captACopier.latitude), description(captACopier.description)
{

}

void Capteur::setSensorId(string sensorId)
{
    this->sensorId = sensorId;
}

void Capteur::setLongitude(int longitude)
{
    this->longitude = longitude;
}

void Capteur::setDescription(string description)
{
    this->description = description;
}

void Capteur::setLattitude(int lattitude)
{
    this->latitude = lattitude;
}

int Capteur::getLongitude() const
{
    return longitude;
} 

int Capteur::getLatitude() const
{
<<<<<<< HEAD
    return this->latitude;
=======
    return lattitude;
>>>>>>> 53a0ae5d333d37c659bbae42608dbb316434e22e
}

string Capteur::getSensorId() const
{
    return sensorId;
} 

string Capteur::getDescription() const
{
    return description;
} 

string Capteur:: caracteristiqueDeLair() const
{
    //aller dans gestionMesure chercher les infos
    return ""; 
}

void Capteur::afficher() const
{
    cout << "L'Id est " << this->sensorId << endl;
    cout << "La description est  " << this->description << endl;
    cout << "La lattitude est " << this->latitude <<endl;
    cout << "La longitude est " << this->longitude <<endl;
}
