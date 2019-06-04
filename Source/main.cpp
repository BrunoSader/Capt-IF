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
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cstring>
#include <iomanip>
#include <unistd.h>
#include <algorithm>

using namespace std;

//------------------------------------------------------ Include personnel


#include "../En-tete/GestionCapteur.h"
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"
#include "../En-tete/Warning.h"

void menu(GestionCapteur* gc, GestionMesure* gm) ;

bool operator == (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min) return true;
	else return false;
}
bool operator < (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year < tm2.tm_year){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon < tm2.tm_mon){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday < tm2.tm_mday){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour < tm2.tm_hour){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min < tm2.tm_min){return true;}
	else return false;
}

int main(int argc, char *argv[])
{

	//le premier argument correspond au nom du fichier avec les différents types d'attributs
	string nomFichierAttribut = string(argv[1]);
	//le second correspond à la description de capteurs
	string nomFichierDescriptionCapteur = string(argv[2]);
	//le dernier correspond aux des données capteurs
	string nomFichierDonnesCapteur = string(argv[3]);
	/*rajouter le code qui execute cette commande dans le terminal : iconv -f utf-16 -t utf-8 fichier_original > nouveaufichier*/
	execl("iconv", "-f",  "utf-16", "-t",  "utf-8", "../Ressources/FichierTest.csv", ">", "new3.csv");
	//**********Stockage des Attributs dans le tableau de gestion mesure
	GestionMesure *gm = new GestionMesure();
	Warning *warning = new Warning();
	string chaine;
	string sacrifie;
	fstream fichier;
	fichier.open(nomFichierAttribut, ios::in);
	if (fichier)
	{
		getline(fichier, chaine);
		while (!fichier.eof())
		{
			stringstream ss;
			getline(fichier, chaine);
			ss << chaine;
			string id;
			string description;
			string unite;
			getline(ss, id, ';');
			getline(ss, unite, ';');
			getline(ss, description, ';');
			gm->ajouterAttribut(id, unite, description);
		}
	}else{
		cout<<"marche pas"<<endl;
	}
	cout<<gm->consulterType()<<endl;
	//**********Stockage des Capteurs dans le tableau de gestion capteur
	GestionCapteur *gc = new GestionCapteur();
	fstream fichier2;
	fichier2.open(nomFichierDescriptionCapteur, ios::in);
	if (fichier2)
	{
		getline(fichier2, chaine);
		while (!fichier2.eof())
		{
			stringstream ss;
			getline(fichier2, chaine);
			ss << chaine;
			string id;
			int lattitude;
			int longitude;
			string description;
			getline(ss, id, ';');
			ss >> lattitude;
			getline(ss, sacrifie, ';');
			ss >> longitude;
			getline(ss, sacrifie, ';');
			getline(ss, description, ';');
			gc->ajouterCapteur(id, lattitude, longitude, description);
		}
	}else{
		cout<<"marche pas"<<endl;
	}
	cout<<gc->afficherCapteur()<<endl;

	//**********Stockage des données des capteurs
	fstream fichier3;
	fichier3.open(nomFichierDonnesCapteur, ios::in);
	if (fichier3)
	{
		for(int i = 0; i < 15; getline(fichier3, chaine), i++){}
		while (!fichier3.eof())
		{
			stringstream ss;
			getline(fichier3, chaine);
			ss << chaine;
			int annee;
			int mois;
			int jour;
			int heure;
			int minutes;
			double secondes;
			string sensorId;
			string attributeId;
			double valueS;
			ss >> annee;
			getline(ss, sacrifie, '-');
			ss >> mois;
			getline(ss, sacrifie, '-');
			ss >> jour;
			getline(ss, sacrifie, 'T');
			ss >> heure;
			getline(ss, sacrifie, ':');
			ss >> minutes;
			getline(ss, sacrifie, ':');
			ss >> secondes;
			getline(ss, sacrifie, ';');
			getline(ss, sensorId, ';');
			getline(ss, attributeId, ';');
			ss >> valueS;
			getline(ss, sacrifie, ';');
			struct tm tm {};
			tm.tm_year = annee;
			tm.tm_mon = mois ;
			tm.tm_mday = jour ;
			tm.tm_hour = heure;
			tm.tm_min = minutes;
			tm.tm_sec = secondes;
			gm->ajouterMesure(tm, sensorId, attributeId, valueS);
			if(warning->valeurAuDelaSeuil(attributeId, valueS)){cout<<"WARNING!!! Votre capteur "<<sensorId<<" depasse le seuil de l'attribut "<<attributeId<<" avec une valeur de "<<valueS<<endl;}
			else if(warning->calculerDonneePrevisionelle(gm->getMesure(sensorId),attributeId)){cout<<"WARNING!!! Votre capteur "<<sensorId<<" depassera le seuil de l'attribut "<<attributeId<<" dans 5 temps"<<endl;}
		}
	}
	//cout<<gm->consulterMesure()<<endl;

	menu(gc, gm);
	delete gm;
	delete gc;
	return 0;
} //----- fin de main


void promptConsole (const string& prompt, const string& color) {
#ifdef MAP
    cout << "Appel à la méthode promptConsole de <Application>" << endl;
#endif
    cout << color << prompt << /*RESET <<*/ endl;
} //----- Fin de prompt

void promptConsole (const char* prompt, const string& color) {
#ifdef MAP
    cout << "Appel à la méthode promptConsole de <Application>" << endl;
#endif
    cout << color << prompt << /*RESET << */endl;
} //----- Fin de prompt

void getInput(const string& prompt, const string& color, string& result)
{
#ifdef MAP
    cout << "Appel à la méthode getInput de <Application>" << endl;
#endif
    while (true) {
        cout << color << prompt << /*RESET <<*/ endl << "> ";
        getline(cin, result);
        if (!result.empty())
            return;
        else if (cin.eof()) {
            cin.clear();
            return;
        }
        else
            promptConsole("Entree Vide\n", "ROUGE");
    }
} //----- Fin de getInput

int getChoice (int range, const string& prompt, string* choices)
// Algorithme : On donne les choix et on lire le choix d'utilisateur
{
#ifdef MAP
    cout << "Appel à la méthode getChoice de <Application>" << endl;
#endif
    while (true) {
        promptConsole(prompt, "BLEU");
        if (choices != NULL) {
            for (int i = 0; i < range; i++) {
                promptConsole(to_string(i + 1) + ". " + choices[i], "Couleur");
            }
        }
        cout << "> ";
        int n;
        cin >> n;
        if (cin && n > 0 && n <= range) {
            cin.ignore(INT8_MAX, '\n');
            return n;
        }
        else if (cin.eof()) {
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
            return -1;
        }
        else {
            promptConsole("Entrée invalide veuillez réessayer\n", "ROUGE");
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
        }
        cout << endl;
    }
} //----- Fin de getChoice

int getChoice (int start, int end, const string& prompt)
// Algorithme : On donne les choix et on lire le choix d'utilisateur
{
#ifdef MAP
    cout << "Appel à la méthode getChoice de <main>" << endl;
#endif
    while (true) {
        promptConsole(prompt, "BLEU");
        cout << "> ";
        int n;
        cin >> n;
        if (cin && n >= start && n <= end) {
            cin.ignore(INT8_MAX, '\n');
            return n;
        }
        else if (cin.eof()) {
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
            return INT8_MIN;
        }
        else {
            promptConsole("Entrée invalide, veuillez réessayer \n", "ROUGE");
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
        }
        cout << endl;
    }
} //----- Fin de getChoice

void paramDonnees()
{
#ifdef MAP
    cout << "Appel à la méthode paramDonnees de <main>" << endl;
#endif

    string * arg = new string[7];
    int taille = 5;
    int * boolTab = new int[taille];
    for (int i = 0; i<taille; i++) {
        boolTab[i]=0;
    }

    string prompt("Choisissez les paramètres que vous souhaitez renseigner \n Sachant que vous pouvez renseigner un sensorId OU des coordonnées OU un intervalle de coordonnées mais pas une combinaison de ces paramètres");
    cout << endl;
    string choice1("sensorId");
    string choice2("coordonnées");
    string choice3("intervalle de coordonnées");
    cout << endl;
    string choice4("dates");
    string choice5("attributeId");
    cout << endl;
    string choice6("Valider la recherche de mesures");
    string choices[6] = {choice1, choice2, choice3, choice4, choice5, choice6};

    bool runParam = true;
    while (runParam) {
        int choice = getChoice(6, prompt, choices);
        switch (choice) {
            case 1:
            {
                boolTab[0]=1;

                string sensorId;
                string prompt("Veuillez renseigner le sensorId : ");
                getInput(prompt, "BLEU", sensorId);

                cout<<sensorId;

            }
                break;
            case 2:
                boolTab[1]=1;

                break;
            case 3:
                boolTab[2]=1;

                break;
            case 4:
                boolTab[3]=1;

                break;
            case 5:
                boolTab[4]=1;

                break;
            case 6:

                break;
        }
        cout << endl << endl;
    }
} //----- Fin de paramDonnees

void choixCapteur(int numero, GestionMesure* gm, GestionCapteur* gc, double confiance){
	int rep;
	int lattitude = 0;
	int longitude = 0;
	string texte = " ";
	if(numero == 3) cout<<"Voulez-vous supprimer un capteur à l'aide de ses coordonnées (1) ou son Id (2) ?"<<endl;
	if(numero == 4) cout<<"Voulez-vous surveiller un capteur à l'aide de ses coordonnées (1) ou son Id (2) ?"<<endl;
	if(numero == 5) cout<<"Voulez-vous rechercher un capteur à l'aide de ses coordonnées (1) ou son Id (2) ?"<<endl;
	if(numero == 6) cout<<"Voulez-vous trouver les capteurs similaires à l'aide des coordonnées (1) de votre capteur ou son Id (2) ?"<<endl;
		cin>>rep;
                if(rep == 1){
			cout <<"Veuillez rentrer la lattiude"<<endl;
			cin >> lattitude;
			cout << "Veuillez rentrer la longitude"<<endl;
			cin >> longitude;
			if(numero == 3){
				if(gc->supprimerCapteur(1, lattitude, longitude, texte)) cout<<"Le capteur a bien été supprimé"<<endl;
				else cout<<"erreur lors de la suppression du capteur"<<endl;
			}
			if(numero == 4) {
				if(gc->surveillerCapteur(1, lattitude, longitude, texte, gm)){
					cout<<"Le Capteur est ne présente pas d'anomalie"<<endl;
				} else {
					cout<<"Le Capteur n'est pas conforme et présente des anomalies."<<endl;
				}
			}
			if(numero == 5) cout<<"L'identifiant du capteur ayant les coordonnées les plus proches de celles que vous avez renseignés est " << gc->rechercherCapteur(lattitude, longitude).getSensorId()<<endl;
			if(numero == 6) cout<<gc->capteursSimilaires(1, lattitude, longitude, texte, gm, confiance)<<endl;
		} else if(rep == 2){
			cout << "Veuillez rentrer l'Id du capteur" <<endl;
			cin >> texte;
			if(numero == 3){
				if(gc->supprimerCapteur(2, lattitude, longitude, texte)) cout<<"le capteur a bien été supprimé"<<endl;
				else cout<<"erreur lors de la suppression"<<endl;
			}
			if (numero == 4) {
				if(gc->surveillerCapteur(2, lattitude, longitude, texte, gm)){
					cout<<"Le Capteur ne présente pas d'anomalie"<<endl;
				} else {
					cout<<"Le Capteur n'est pas conforme et présente des anomalies"<<endl;
				}
			}
			if (numero == 5) cout<<"La lattitude du capteur ayant l'identifiant que vous avez renseignés est " <<gc->rechercherCapteur(texte).getLattitude() << " et sa longitude est "<<gc->rechercherCapteur(texte).getLongitude();
			if (numero == 6) cout<<gc->capteursSimilaires(2, lattitude, longitude, texte, gm, confiance)<<endl;
		} else cout <<"numéro invalide"<<endl;
}


void menuGestionCapteur(GestionCapteur* gc, GestionMesure* gm)
{
#ifdef MAP
    cout << "Appel à la méthode menuGestionCapteur de <main>" << endl;
#endif
    string prompt("Veuillez choisir une des suivantes :");
    string choice1("Consulter la liste des capteurs");
    string choice2("Ajouter un capteur");
    string choice3("Supprimer un capteur");
    string choice4("Surveiller un capteur");
    string choice5("Rechercher un capteur");	//On en fait quoi du capteur qu'il a rechercher ? on affiche ses infos? ses mesures ?
    string choice6("Capteurs similaires");
    string choice7("Retour au menu de départ");
    string choices[7] = {choice1, choice2, choice3, choice4, choice5, choice6, choice7};

    bool runCapteur = true;
    while (runCapteur) {
        int choice = getChoice(7, prompt, choices);
	double rep = 0;
	int lattitude = 0;
	int longitude = 0;
	string texte = " ";
        switch (choice) {
            case 1:
                cout<<gc->afficherCapteur()<<endl;
                break;
            case 2:
		cout<<"Entrer la longitude"<<endl;
		cin>>longitude;
		cout<<"Entrer la lattitude"<<endl;
		cin>>lattitude;
		cout<<"Entrer une description"<<endl;
		cin>>texte;
                gc->ajouterCapteur(lattitude, longitude, texte);
                break;
            case 3:
		choixCapteur(3, gm, gc, rep);
                break;
            case 4:
		choixCapteur(4, gm, gc, rep);
                break;
            case 5:
		choixCapteur(5, gm, gc, rep);
                break;
            case 6:
		cout<<"Veuillez entrer le poucentage de precision que vous souhaitez (entre 0 et 1)"<<endl;
		cin >> rep;
                choixCapteur(6, gm, gc, rep);
                break;
            case 7:
                runCapteur = false;
                promptConsole("Retour au menu", "VERT");
                cout << endl << endl;
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menuGestionCapteur

void menuGestionMesure(GestionMesure* gm)
{
#ifdef MAP
    cout << "Appel à la méthode menuGestionMesure de <main>" << endl;
#endif
    string prompt("Veuillez choisir une des fonctionnalités suivantes :");
    string choice1("Consulter la liste des attributs");
    string choice2("Consulter les données");
    string choice3("Données similaires");
    string choice4("Consulter mesure(s)");
    string choice5("Calculer moyenne de valeurs");
    string choice6("Retour au Menu de départ");
    string choices[6] = {choice1, choice2, choice3, choice4, choice5, choice6};

    bool runMesure = true;
    while (runMesure) {
        int choice = getChoice(6, prompt, choices);
        switch (choice) {
            case 1:
                cout<<gm->consulterType()<<endl;
                break;
            case 2:
                cout<<gm->consulterMesure()<<endl;
                break;
            case 3:

                break;
            case 4:
                paramDonnees();
                break;
            case 5:

                break;
            case 6:
                runMesure = false;
                promptConsole("Retour au menu", "VERT");
                cout << endl << endl;
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menuGestionMesure

void menu(GestionCapteur* gc, GestionMesure* gm)
{
#ifdef MAP
    cout << "Appel à la méthode menu de <main>" << endl;
#endif
    string prompt("Pour utiliser l'application Capt'air veuillez sélectionner une catégorie du menu :");
    string choice1("Gestion Capteur");
    string choice2("Gestion Mesures");
    string choice3("Gestion Alertes");
    string choice4("Quitter l'application");
    string choices[4] = {choice1, choice2, choice3, choice4};

    bool run = true;
    while (run) {
        int choice = getChoice(4, prompt, choices);
        switch (choice) {
            case 1:
                cout << endl << endl;
                menuGestionCapteur(gc, gm);
                break;
            case 2:
                cout << endl << endl;
                menuGestionMesure(gm);
                break;
            case 3:

                break;
            case 4:
                run = false;
                promptConsole("A bientôt", "VERT");
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menu
