/*************************************************************************
                           Warning  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Warning> (fichier Warning.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Warning.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

void Warning::entrerDecision(Decision laDecision,double valeur)
// Algorithme :
//
{
	map<Decision,double>::iterator decision_exist;
	decision_exist = listeDecision.find(laDecision);
	if (decision_exist == listeDecision.end())
	//Decision n'existe pas
	{
		listeDecision.insert(std::pair<Decision,double>(laDecision,valeur));
	}
}

void Warning::evaluerDecision(double valeurActuel)
// Algorithme :
//
{
	map<Decision,double>::iterator decision_it;
	for (decision_it=listeDecision.begin(); decision_it!=listeDecision.end() || decision_it->second>-1; ++decision_it){}
	map<Decision,double>::iterator decision_exist;
	Decision laDecision = decision_it->first;
	decision_exist = listeDecision.find(laDecision);
	if(decision_exist==listeDecision.end())
	//Decision n'existe pas
	{
		double difference = valeurActuel - decision_it->second;
		if(difference<0)
		{
			laDecision.setNote(5);
		} else if(difference==0){
			laDecision.setNote(4);
		} else {
			double evolution = difference/decision_it->second;
			if(evolution>0.99)
			{
				laDecision.setNote(0);
			}else if(evolution>0.66)
			{
				laDecision.setNote(1);
			}else if(evolution>0.33)
			{
				laDecision.setNote(2);
			}
			else if(evolution>0)
			{
				laDecision.setNote(2);
			}
		}
		decision_it->second = -1;
	}
}


double Warning::calculerDonneePrevisionelle (string sensorID, map<string,map<time_t,map<string,double>>> listeMesurebyCapteur, Attribut lAttribut)
// Algorithme :
//
{
	map<string,map<time_t,map<string,double>>>::iterator sensor_it;
	sensor_it = listeMesurebyCapteur.find(sensorID);
	//On trouve notre capteur dans la liste
	if (sensor_it != listeMesurebyCapteur.end())
	{
		map<time_t,map<string,double>> listeMesurebyDate = sensor_it->second;
		map<time_t,map<string,double>>::reverse_iterator date_it;
		//On itere d sur les dates decroissantes
		map<string,double>::iterator attribut_it;
		double* values = new double [5];
		int cpt=0;
		for (date_it=listeMesurebyDate.rbegin(); date_it!=listeMesurebyDate.rend(); ++date_it)
		{
			attribut_it = date_it->second.find(lAttribut.getAttributeId());
			//On trouve l'attribut sur lequel on aimerait calculer les donnees previsionelles
			values[cpt] = attribut_it->second;
			cpt++;
		}
		double difference = (values[0]-values[1])*0.5 + (values[1]-values[2])*0.25 + (values[2]-values[3])*0.15 + (values[3]-values[4])*0.1;
		//Calcul de la difference
		return (values[0]*difference);
	}else return -1;
}
//----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
Warning & Warning::operator = ( const Warning & unWarning )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Warning::Warning ( const Warning & unWarning )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Warning>" << endl;
#endif
} //----- Fin de Warning (constructeur de copie)

Warning::Warning ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Warning>" << endl;
#endif
} //----- Fin de ~Warning


Warning::~Warning ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Warning>" << endl;
#endif
} //----- Fin de ~Warning


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
