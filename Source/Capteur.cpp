#include "Capteur.h"

#include <cmath>
#include <iostream>
#include<string>
using namespace std;

Capteur::Capteur() : sensorId(" "), longitude(-1000), lattitude(-1000), description(" ")
{}

Capteur::Capteur(string sensorId, int longitude, int lattitude, string description) : sensorId(sensorId), longitude(longitude), lattitude(lattitude), description(description)
{}

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
    this->lattitude = lattitude;
}

int Capteur::getLongitude() const
{
    return this->longitude;
} 

int Capteur::getLattitude() const
{
    return this->lattitude;
}

string Capteur::getSensorId() const
{
    return this->sensorId;
} 

string Capteur::getDescription() const
{
    return this->description;
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