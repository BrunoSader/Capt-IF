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
using namespace std;

//------------------------------------------------------ Include personnel
#include "../En-tete/Warning.h"


int main()
{
	Warning monWarning = Warning(1,"hello");
	cout<<"in main"<<endl;
	return 0;
} //----- fin de main
