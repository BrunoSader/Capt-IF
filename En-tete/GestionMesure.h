/*************************************************************************
                           GestionMesure  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <GestionMesure> (fichier GestionMesure.h) ------
#if ! defined ( GESTIONMESURE_H )
#define GESTIONMESURE_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <time>
#include "Attribut.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <GestionMesure>
//
//
//------------------------------------------------------------------------

class GestionMesure
{
//----------------------------------------------------------------- PUBLIC

public:

		map<String, map<String, map<String,int>>> listeMesure;
		vector<Attribut> listeTypeMesure;
//----------------------------------------------------- M�thodes publiques

		String consulterType( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		String consulterMesure( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		vector<Mesure> getMesure(time_t laDate);
    // Mode d'emploi :
    //
    // Contrat :
    //

		int getMesure(time_t laDate);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
    GestionMesure & operator = ( const GestionMesure & unGestionMesure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GestionMesure ( const GestionMesure & unGestionMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionMesure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionMesure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <GestionMesure>

#endif // GESTIONMESURE_H
