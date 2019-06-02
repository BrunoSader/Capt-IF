/*************************************************************************
					  main  -  description
				 -------------------
	début        :
	copyright    :
	e-mail       :
*************************************************************************/

//---------- Interface du module <main> (fichier main.h) ----------------
#if ! defined ( MAIN_H )
#define MAIN_H

// Rôle du module <main>
// Représente seulement la classe permettant d'appeler l'interface
// créée dans la classe Interface afin d'afficher un visuel pour l'utilisateur

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#if defined(__linux__) || defined(__iunix__)
const string ROUGE = "\033[1;31m";
const string VERT  = "\033[1;32m"; 
const string BLEU  = "\033[1;34m";
const string RESET = "\033[0m";
#else
const string ROUGE = "";
const string VERT  = ""; 
const string BLEU  = "";
const string RESET = "";
#endif

#include "Warning.h"
#include "GestionMesure.h"
#include "GestionCapteur.h"

//----------------------------------------------------------------- PUBLIC
//---------------------------------------------------- Fonctions publiques

	int main(int argc, char ** argv);

	void promptConsole (const string& prompt, const string& color = RESET);
	void promptConsole (const char* prompt, const string& color = RESET);
	void getInput(const string& prompt, const string& color, string& result);
	int getChoice (int range, const string& prompt, string* choices);
	int getChoice (int start, int end, const string& prompt);

	void menuGestionCapteur();
	void menuGestionMesure();
	void menu();

#endif // MAIN_H
