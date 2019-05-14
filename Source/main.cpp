/*************************************************************************
		   main  -  description
				 -------------------
	début        :
	copyright    :
	e-mail       :
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) -------------

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Warning.h"
#include "../En-tete/Attribut.h"


int main()
{
	map<string,map<time_t,map<string,int>>> listeMesurebyCapteur;
	map<time_t,map<string,int>> listeMesurebyDate;
	map<string,int> listeMesurebyAttribut;

	listeMesurebyAttribut.insert( std::pair<string,int>("O3",100) );
	listeMesurebyAttribut.insert( std::pair<string,int>("N3",100) );
	time_t date;
	listeMesurebyDate.insert( std::pair<time_t,map<string,int>>(date,listeMesurebyAttribut) );

	listeMesurebyAttribut.insert( std::pair<string,int>("O3",50) );
	listeMesurebyAttribut.insert( std::pair<string,int>("N3",50) );
	time_t date2;
	listeMesurebyDate.insert( std::pair<time_t,map<string,int>>(date2,listeMesurebyAttribut) );

	listeMesurebyAttribut.insert( std::pair<string,int>("O3",50) );
	listeMesurebyAttribut.insert( std::pair<string,int>("N3",50) );
	time_t date3;
	listeMesurebyDate.insert( std::pair<time_t,map<string,int>>(date3,listeMesurebyAttribut) );

	listeMesurebyAttribut.insert( std::pair<string,int>("O3",50) );
	listeMesurebyAttribut.insert( std::pair<string,int>("N3",50) );
	time_t date4;
	listeMesurebyDate.insert( std::pair<time_t,map<string,int>>(date4,listeMesurebyAttribut) );

	listeMesurebyAttribut.insert( std::pair<string,int>("O3",50) );
	listeMesurebyAttribut.insert( std::pair<string,int>("N3",50) );
	time_t date5;
	listeMesurebyDate.insert( std::pair<time_t,map<string,int>>(date5,listeMesurebyAttribut) );

	listeMesurebyCapteur.insert( std::pair<string,map<time_t,map<string,int>>>("capteur1",listeMesurebyDate) );
	Attribut att = Attribut("N3","g/m3","description",30);
	Warning mesWarnings = Warning(1,"N3");
	cout<<mesWarnings.calculerDonneePrevisionelle("capteur1",listeMesurebyCapteur,att)<<endl;
	return 0;
} //----- fin de main
