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
#include <string>
#include <iostream>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//------------------------------------------------- Surcharge d'op�rateurs

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool Warning::valeurAuDelaSeuil(string attribut, double val)
{
	if(attribut == "O3")
	{
		if(val>=180)
		{
			return true;
		}
	}
	if (attribut == "NO2")
	{
		if(val>=200)
		{
			return true;
		}
	}
	if (attribut == "SO2")
	{
		if(val>=300)
		{
			return true;
		}
	}
	if (attribut == "PM10")
	{
		if(val>=50)
		{
			return true;
		}
	}
	return false;

}

void Warning::entrerDecision(Decision laDecision,double valeur)
// Algorithme :
//
{
	map<Decision,double,DecisionCompare>::iterator decision_exist;
	decision_exist = listeDecision.find(laDecision);
	if (decision_exist == listeDecision.end())
	//Decision n'existe pas
	{
		listeDecision.insert(std::pair<Decision,double>(laDecision,valeur));
	} else cout <<"Decision existe deja"<<endl;
}

void Warning::evaluerDecision(string sensorId, double valeurActuel)
// Algorithme :
//
{
	map<Decision,double,DecisionCompare>::iterator decision_it;
	for (decision_it=listeDecision.begin();decision_it!=listeDecision.end() && decision_it->first.getSensorId()!=sensorId; ++decision_it){}
	if(decision_it!=listeDecision.end())
	{
		Decision *laDecision = new Decision(decision_it->first);
		double difference = valeurActuel - decision_it->second;
		if(difference<0)
		{
			laDecision->setNote(5);
		} else if(difference==0){
			laDecision->setNote(4);
		} else {
			double evolution = difference/decision_it->second;
			if(evolution>0.99)
			{
				laDecision->setNote(0);
			}else if(evolution>0.66)
			{
				laDecision->setNote(1);
			}else if(evolution>0.33)
			{
				laDecision->setNote(2);
			}
			else if(evolution>0)
			{
				laDecision->setNote(3);
			}
		}
		listeDecision.erase(decision_it);
		listeDecision.insert(std::pair<Decision,double>(*laDecision,-1));
		cout<<"Decision prise pour capteur "<<laDecision->getSensorId()<<" et sa note est de "<<laDecision->getNote()<<endl;
	}
}

Decision Warning::proposerDecision()
{
	if(listeDecision.size()>0)
	{
		map<Decision,double,DecisionCompare>::iterator decision_it;
		decision_it=listeDecision.begin();
		//cout<<"la note"<<decision_it->first.getNote()<<endl;
		return decision_it->first;
	} else {
		bool* action = new bool[4];
		Decision *mauvaiseDecision = new Decision(action,"",0);
		return *mauvaiseDecision;
	}
}


bool Warning::calculerDonneePrevisionelle (map<struct tm, map<string,double>>listeMesurebyDate, string lAttribut)
// Algorithme :
//
{
	map<struct tm, map<string,double>>::reverse_iterator date_it;
	//On itere d sur les dates decroissantes
	map<string,double>::iterator attribut_it;
	double* values = new double [5];
	int cpt=0;
	for (date_it=listeMesurebyDate.rbegin(); date_it!=listeMesurebyDate.rend() && cpt<6; ++date_it)
	{
		attribut_it = date_it->second.find(lAttribut);
		//On trouve l'attribut sur lequel on aimerait calculer les donnees previsionelles
		values[cpt] = attribut_it->second;
		cpt++;
	}
	if(cpt>=5){
		double coef = (values[0]-values[4])/5;
		double ordo_ori = values[0]-(coef*5);
		double valeur_futur= coef*10+ordo_ori;
		return valeurAuDelaSeuil(lAttribut, valeur_futur);
	}else return false;
}
//----- Fin de M�thode

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
