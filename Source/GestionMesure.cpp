/*************************************************************************
                           GestionMesure  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <GestionMesure> (fichier GestionMesure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../En-tete/GestionMesure.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type GestionMesure::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

/*Warning GestionMesure::alerterSurMesure(Mesure uneMesure)
{
 Warning wa;
  if ( a.getAttributeId() == uneMesure.getAttributeId() && uneMesure.getValue() > a.getValeurSeuil() ) */
 /*return wa;
}*/




//------------------------------------------------- Surcharge d'op�rateurs
GestionMesure & GestionMesure::operator = ( const GestionMesure & unGestionMesure )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GestionMesure::GestionMesure ( const GestionMesure & unGestionMesure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionMesure>" << endl;
#endif
} //----- Fin de GestionMesure (constructeur de copie)


GestionMesure::GestionMesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionMesure>" << endl;
#endif
} //----- Fin de GestionMesure


GestionMesure::~GestionMesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionMesure>" << endl;
#endif
} //----- Fin de ~GestionMesure

string GestionMesure::consulterType( )
{
    string res; 
    for(unsigned int i=0; i<listeTypeMesure.size(); ++i)
    {
        res += listeTypeMesure[i].getDescription();
        res += "\n";
    }
    return res;
}

string GestionMesure::consulterMesure( )
{
    string res;
   for(map<string, map<time_t, map<string,double>>>::iterator i=listeMesure.begin(); i!=listeMesure.end(); ++i) {
        res += i->first ;
        res += "\n";
        for(map<time_t, map<string,double>>::iterator i2=i->second.begin(); i2!=i->second.end(); ++i2) {
            res += i2->first ;
            res += "\n";
             for(map<string,double>::iterator i3=i2->second.begin(); i3!=i2->second.end(); ++i3) {
                  res += i3->first ;
                  res += "\n";
             }
        }
    }
    return res;
}


vector<Mesure> GestionMesure::getMesure(time_t laDate)
{
    vector <Mesure> res;
      /*  for(map<string, map<time_t, map<string,int>>>::iterator i=listeMesure.begin(); i!=listeMesure.end(); ++i) {
             map<time_t, map<string,int>>::iterator it;
        	it = i->second.find(laDate);
        	if (it != i->second.end())
	           {
	               for(map<string,int>::iterator i3=it->second.begin(); i3!=it->second.end(); ++i3) {
                  res += i3->first ;
                  res += "\n";
             }
	            }*/
    return res;
}


int GestionMesure::moyenneValAttribut(Attribut at)
{
    return 0;
}

void GestionMesure::ajouterAttribut(string id, string unite, string description)
{
	listeTypeMesure.push_back(Attribut(id, unite, description, 0));
}

void GestionMesure::ajouterMesure(time_t timestamp, string sensorId, string attributeId, double value)
{
	//map<string, map<time_t, map<string,double>>> listeMesure;

	/*SensorId
	Date
	AttributeId
	Valeure*/
	/*map<string, map<time_t, map<string,double>>>::iterator it = listeMesure.find(sensorId);
	for(int i = 0; i < listeMesure.size(); i++){
		if(it == listeMesure.end()){
			map<string, double> mp;
			mp.insert(make_pair(attributeId, value));
			map<time_t, map<string,double>> mp2;
			mp2.insert(make_pair(timestamp, mp));
			listeMesure.insert(make_pair(sensorId, mp2));
		} else{
			it = listeMesure.begin();
			for(int i2 = 0; i2 < it->second.size(); i2++){
			map<time_t, map<string,double>> it2 = it->second.find(time_t);
			if(it2 == it->second.end()){
				map<time_t, map<string,double>> mp2;
				mp2.insert(make_pair(timestamp, it->second));
				it->second.insert(make_pair(sensorId, mp2));
			}else{
				
				it->second.insert(make_pair(sensorId, it->second));
			}
		it2++;
		}
		it++;*/

			
				
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
