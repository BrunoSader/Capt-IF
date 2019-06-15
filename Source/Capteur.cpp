#include "../En-tete/Capteur.h"

#include <cmath>
#include <iostream>
#include<string>
using namespace std;

Capteur::Capteur() : sensorId(" "), longitude(-1000), lattitude(-1000), description(" ")
{}

Capteur::Capteur(string sensorId, double longitude, double lattitude, string description) : sensorId(sensorId), longitude(longitude), lattitude(lattitude), description(description)
{}

void Capteur::setSensorId(string sensorId)
{
    this->sensorId = sensorId;
}

void Capteur::setLongitude(double longitude)
{
    this->longitude = longitude;
}

void Capteur::setDescription(string description)
{
    this->description = description;
}

void Capteur::setLattitude(double lattitude)
{
    this->lattitude = lattitude;
}

double Capteur::getLongitude() const
{
    return longitude;
}

double Capteur::getLattitude() const
{
    return lattitude;
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
    cout << "La lattitude est " << this->lattitude <<endl;
    cout << "La longitude est " << this->longitude <<endl;
}
