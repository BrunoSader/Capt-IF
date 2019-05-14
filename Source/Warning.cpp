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
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Warning.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Warning::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


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
    cout << "Appel au constructeur de <Warning>" << endl;
#endif
} //----- Fin de Warning


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
