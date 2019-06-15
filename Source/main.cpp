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
#include <chrono>

using namespace std;

//------------------------------------------------------ Include personnel

#include "../En-tete/GestionCapteur.h"
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"
#include "../En-tete/Warning.h"
#include "../En-tete/main.h"

void menu(GestionCapteur* gc, GestionMesure* gm);

void gestionDesDecisions(Warning* wr, double valeur, string sensorId);

int main(int argc, char *argv[])
{

	//le premier argument correspond au nom du fichier avec les différents types d'attributs
	string nomFichierAttribut = string(argv[1]);
	//le second correspond à la description de capteurs
	string nomFichierDescriptionCapteur = string(argv[2]);
	//le dernier correspond aux des données capteurs
/*	int rep = -1;
	string nomFichier;
	string nomFichierDonnesCapteur;
	while(rep != 1 && rep !=2){
					cout<<"Souhaitez vous rentrer un fichier pour les données en utf16 (1) ou utf8 (2) ?"<<endl;
					cin >> rep;
					cout<<"Veuillez entrer le nom du fichier"<<endl;
					cin >> nomFichier;
					if(rep == 1) {
						string chemin = "iconv -f utf-16 -t utf-8 ../Ressources/" + nomFichier + " > new3.csv";
						system(chemin.c_str());
					  nomFichierDonnesCapteur = "new3.csv";
					} else if(rep == 2) nomFichierDonnesCapteur = nomFichier;
				  else cout<<"numero invalide"<<endl;
 }*/
 string nomFichierDonnesCapteur = string(argv[3]);
	//**********Stockage des Attributs dans le tableau de gestion mesure
	GestionMesure *gm = new GestionMesure();
	Warning *warning = new Warning();
	string chaine;
	string sacrifie;
	fstream fichier;
	fichier.open(nomFichierAttribut, ios::in);
	if (fichier)
	{
		int seuil;
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
			    if ("O3"==id)
			    {
				seuil=180;
			    }
			    else if ("NO2"==id)
			    {
				seuil=200;
				    }
			    else if ("SO2"==id)
			    {
				seuil=300;
			    }
			    else if ("PM10"==id)
			    {
				seuil=50;
			    }
			    else{ seuil = 0; }
					if(id != "") gm->ajouterAttribut(id, unite, description);
		}
	}else{
		cout<<"Ne fonctionne pas"<<endl;
	}
	// cout<<gm->consulterType()<<endl;

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
			double lattitude;
			double longitude;
			string description;
			getline(ss, id, ';');
			ss >> longitude;
			getline(ss, sacrifie, ';');
			ss >> lattitude;
			getline(ss, sacrifie, ';');
			getline(ss, description, ';');
			if(id != "") gc->ajouterCapteur(id, lattitude, longitude, description);
		}
	}else{
		cout<<"Ne fonctionne pas"<<endl;
	}

	//**********Stockage des données des capteurs
	fstream fichier3;
	fichier3.open(nomFichierDonnesCapteur, ios::in);

	ofstream myfile;
    myfile.open ("lectureAleatoire.csv");
	for(int k=10; k<100000000; k=k*5)
	{

	int i = 0;
		if (fichier3)
		{
			while (!fichier3.eof() )
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
				/* if(warning->valeurAuDelaSeuil(attributeId, valueS)){

			  if(sensorId != "") gm->ajouterMesure(tm, sensorId, attributeId, valueS);
				if(i++ < 3){
				if(warning->valeurAuDelaSeuil(attributeId, valueS, gm->getListeAttribut())){
					cout<<"WARNING!!! Votre capteur "<<sensorId<<" depasse le seuil de l'attribut "<<attributeId<<" avec une valeur de "<<valueS<<endl;
					gestionDesDecisions(warning, valueS, sensorId);
				}
				else if(warning->calculerDonneePrevisionelle(gm->getMesure(sensorId),attributeId, gm->getListeAttribut())){
					cout<<"WARNING!!! Votre capteur "<<sensorId<<" depassera le seuil de l'attribut "<<attributeId<<" dans 5 temps"<<endl;
					gestionDesDecisions(warning, valueS, sensorId);

				} else	warning->evaluerDecision(sensorId, valueS); */
				i++;

			}
		}
	}
//	myfile.close();
	menu(gc, gm);
	delete gm;
	delete gc;
	return 0;
} //----- fin de main

/* Pour afficher un string d'une certaine couleur */
void promptConsole (const string& prompt, const string& color) {
#ifdef MAP
    cout << "Appel à la méthode promptConsole de <Application>" << endl;
#endif
    cout << color << prompt << RESET << endl;
} //----- Fin de prompt

void promptConsole (const char* prompt, const string& color) {
#ifdef MAP
    cout << "Appel à la méthode promptConsole de <Application>" << endl;
#endif
    cout << color << prompt << RESET << endl;
} //----- Fin de prompt

/* Pour lire l'entrée de l'utilisateur et la placer dans un string result */
void getInput(const string& prompt, const string& color, string& result)
{
#ifdef MAP
    cout << "Appel à la méthode getInput de <Application>" << endl;
#endif
    while (true) {
        cout << color << prompt << RESET << endl << "> ";
        getline(cin, result);
        if (!result.empty())
            return;
        else if (cin.eof()) {
            cin.clear();
            return;
        }
        else
            promptConsole("Entree Vide\n", ROUGE);
    }
} //----- Fin de getInput

/* Pour renvoyer l'entier correspondant au choix d'un utilisateur, indiqué par un numéro entre 1 et le nombre de choix possibles */
int getChoice (int range, const string& prompt, string* choices)
{
#ifdef MAP
    cout << "Appel à la méthode getChoice de <Application>" << endl;
#endif
    while (true) {
        promptConsole(prompt, BLEU);
        if (choices != NULL) {
            for (int i = 0; i < range; i++) {
                promptConsole(to_string(i + 1) + ". " + choices[i], RESET);
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
            promptConsole("Entrée invalide veuillez réessayer\n", ROUGE);
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
        }
        cout << endl;
    }
} //----- Fin de getChoice

int getChoice (int start, int end, const string& prompt)
{
#ifdef MAP
    cout << "Appel à la méthode getChoice de <main>" << endl;
#endif
    while (true) {
        promptConsole(prompt, BLEU);
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
            promptConsole("Entrée invalide, veuillez réessayer \n", ROUGE);
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
        }
        cout << endl;
    }
} //----- Fin de getChoice

/* Pour sélectionner les paramètres de sélection des mesures/donées de la fonctionnalité getMesure */
void paramDonnees(GestionCapteur* gc, GestionMesure* gm)
{
#ifdef MAP
    cout << "Appel à la méthode paramDonnees de <main>" << endl;
#endif

    string * arg = new string[7];
    int taille = 5;
    bool * boolTab = new bool[taille];
    for (int i = 0; i<taille; i++) {
        boolTab[i]=0;
    }

    string prompt("Choisissez les paramètres que vous souhaitez renseigner \r\n Vous pouvez renseigner soit sensorId soit des coordonnées soit un intervalle de coordonnées.");
    cout << endl;
    string choice1("sensorId");
    string choice2("coordonnées");
    string choice3("intervalle de coordonnées");
    cout << endl;
    string choice4("dates");
    string choice5("attributeId");
    cout << endl;
    string choice6("Valider la recherche de mesures");
    string choice7("Annuler recherche");
    string choices[7] = {choice1, choice2, choice3, choice4, choice5, choice6, choice7};

    bool valide; // utilisé pour valider les entrées

    bool runParam = true;
    Capteur c;
    vector<Capteur> capt;
    map<string, map<struct tm, map<string,double>>> result;
    while (runParam) {
        int choice = getChoice(7, prompt, choices);
        switch (choice) {
            case 1:
            {
                boolTab[0]=1;

                string prompt("Veuillez renseigner le sensorId (ex. : Sensor2) : ");
                getInput(prompt, BLEU, arg[0]); // arg[0] correspond au SensorId renseigné
                c = gc->rechercherCapteur(arg[0]);
                cout << c.getSensorId() << endl;
            }
                break;
            case 2:
                boolTab[1]=1;

                promptConsole("Veuillez renseigner les coordonnées (ex. : latitude=38, longitude =-89) : ",BLEU);

                do {

                    valide = true;

                    string promptLat("Latitude (comprise entre -90 et +90) :");
                    getInput(promptLat, RESET, arg[0]); // arg[0] correspond à la latitude renseignée
                    string promptLon("Longitude (comprise entre -180 et +180) :");
                    getInput(promptLon, RESET, arg[1]); // arg[0] correspond à la longitude renseignée

                    c = gc->rechercherCapteur(stof(arg[0]),stof(arg[1]));
                    
                    if (stof(arg[0])<-90 || stof(arg[0])>90 || stof(arg[1])<-180|| stof(arg[1])>180) {
                            promptConsole("Attention les coordonnées doivent être comprises entre -90 et +90 pour la latitude et -180 et +180 pour la longitude",ROUGE);
                            valide = false;
                    }
                } while (!valide);

                c = gc->rechercherCapteur(stof(arg[0]),stof(arg[1]));
                
                break;
            case 3:
                boolTab[2]=1;
     
                promptConsole("Veuillez renseigner l'intervalle de coordonées (sachant que la latitude (-90 à +90) et la longitude (-180 à +180) : ",BLEU);

                do {
                    valide = true;

                    string promptLatMin("Latitude min :");
                    getInput(promptLatMin, RESET, arg[0]); // arg[0] correspond à la latitude min
                    string promptLatMax("Latitude max :");
                    getInput(promptLatMax, RESET, arg[1]); // arg[1] correspond à la latitude max
                    string promptLonMin("Longitude min :");
                    getInput(promptLonMin, RESET, arg[2]); // arg[2] correspond à la longitude min
                    string promptLongMax("Longitude max :");
                    getInput(promptLongMax, RESET, arg[3]); // arg[3] correspond à la longitude max
                    
                    if (stof(arg[0])<-90 || stof(arg[0])>90 || stof(arg[1])<-90 || stof(arg[1])>90 || stof(arg[2])<-180 || stof(arg[2])>180 || stof(arg[3])<-180 || stof(arg[3])>180) {
                        promptConsole("Attention les coordonnées doivent être comprises entre -90 et +90 pour la latitude et -180 et +180 pour la longitude",ROUGE);
                        valide = false;
                    }

                } while (!valide);
                
                capt = gc->rechercherCapteurParIntervalle(stof(arg[0]),stof(arg[1]),stof(arg[2]),stof(arg[3]));
                if (capt.empty()) {
                   promptConsole("Il n'y a aucun capteur compris dans l'intervalle que vous avez sélectionné",ROUGE);
                }
                
                break;
            case 4: // dates

                boolTab[3]=1;
                promptConsole("Veuillez renseigner les deux dates entre lesquelles vous voulez considérer les mesures en précisant les entiers correspondant à l'année, le mois et le jour : ",BLEU);

                do {
                    valide = true;
                    promptConsole("Date de début: ",BLEU);
                    string promptAnnee("Année (1900-020) :");
                    getInput(promptAnnee, RESET, arg[0]); // arg[0] correspond à l'année de début
                    string promptMois("Mois (1-12) :");
                    getInput(promptMois, RESET, arg[1]); // arg[1] mois début
                    string promptJour("Jour (1-31):");

                    getInput(promptJour, RESET, arg[2]); // arg[2] jour début
                    
                    promptConsole("Date de fin: ",BLEU);
                    string promptAnneeF("Année (1900-020) :");
                    getInput(promptAnneeF, RESET, arg[3]); // arg[3] correspond à l'année de fin
                    string promptMoisF("Mois (1-12) :");
                    getInput(promptMoisF, RESET, arg[4]); // arg[4] mois fin
                    string promptJourF("Jour (1-31):");

                    getInput(promptJourF, RESET, arg[5]); // arg[5] jour fin
                    
                    if (stoi(arg[0]) < 1900 || stoi(arg[0]) > 2020 || stoi(arg[3]) < 1900 || stoi(arg[3]) > 2020 // vérif année
                        || stoi(arg[1]) < 1 || stoi(arg[1]) > 12 || stoi(arg[4]) < 1 || stoi(arg[4]) > 12 // vérif mois 
                        || stoi(arg[2]) < 1 || stoi(arg[2]) > 31 || stoi(arg[5]) < 1 || stoi(arg[5]) > 31) 

                    {
                        valide = false;
                        promptConsole("Format de date invalide, veuillez réessayer");
                    }
                    else if (stoi(arg[0]) > stoi(arg[3])) {
                        valide = false;
                        promptConsole("La date de début doit être avant la date de fin");
                    }
                    else if (stoi(arg[1]) > stoi(arg[4])) {
                        valide = false;
                        promptConsole("La date de début doit être avant la date de fin");
                    }
                    else if (stoi(arg[2]) > stoi(arg[5])) {
                        valide = false;
                        promptConsole("La date de début doit être avant la date de fin");
                    }

                } while (!valide);


                break;
            case 5: // attributeId
                { boolTab[4]=1;
                string prompt("Veuillez renseigner l'attributeId (ex. : O3) :");
                getInput(prompt, BLEU, arg[6]); // arg[6] correspond à l'attributeId
                }
                break;
            case 6: //valider
                {
                    if ((boolTab[0]==1 && boolTab[1]==1) || (boolTab[0]==1 && boolTab[2]==1) || (boolTab[1]==1 && boolTab[2]==1)) {
                        promptConsole("Vous ne pouvez pas combiner une recherche par SensorId et coordonnées ou par intervalle de coordonnées et coordonnées. \r\n Veuillez annuler votre opération et recommencer",ROUGE);
                    }
                    else {

                        runParam = false;
                        if (boolTab[0] || boolTab[1]) {
                            result = gm->getMesureCapteur(boolTab,arg,c.getSensorId());
                            cout << gm->consulterMesure(result) << endl;
                        }
                        else if (boolTab[2]) {
                            // map<string, map<struct tm, map<string,double>>> map;
                            for (unsigned int i = 0; i<capt.size(); i++) {
                                result = gm->getMesureCapteur(boolTab,arg,capt[i].getSensorId());
                                cout << gm->consulterMesure(result) << endl;
                            }
                        }
                        else {
                            result = gm->getMesureCapteur(boolTab,arg);
                            cout << gm->consulterMesure(result) << endl;
                        }

                    }
                }
                break;
            case 7: //annuler
                {
                    runParam = false;
                }
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de paramDonnees

/* Appels des fonctions de gestionCapteur */
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
			if(numero == 5 && gc->rechercherCapteur(lattitude, longitude).getSensorId() != "null") cout<<"L'identifiant du capteur ayant les coordonnées les plus proches de celles que vous avez renseignés est " << gc->rechercherCapteur(lattitude, longitude).getSensorId()<<endl;
		  if(numero == 5 && gc->rechercherCapteur(lattitude, longitude).getSensorId() == "null") cout<<"Ce SensorId n'existe pas"<<endl;
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
			if (numero == 5 && gc->rechercherCapteur(texte).getSensorId() != "null") cout<<"La lattiude du sensor que vous avez renseigné est " <<gc->rechercherCapteur(texte).getLattitude()<<" et sa longitude est "<< gc->rechercherCapteur(texte).getLongitude() << endl;
			if (numero == 5 && gc->rechercherCapteur(texte).getSensorId() == "null") cout<<"Ce SensorId n'existe pas"<<endl;
			if (numero == 6) cout<<gc->capteursSimilaires(2, lattitude, longitude, texte, gm, confiance)<<endl;
		} else cout <<"numéro invalide"<<endl;
}

/* LES DIFFERENTS ONGLETS DU MENU */

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
    string choice5("Rechercher un capteur");
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
		cout<<"Veuillez entrer le poucentage de precision que vous souhaitez (entre 0 et 1), 1 étant une correspondance parfaite"<<endl;
		cin >> rep;
                choixCapteur(6, gm, gc, rep);
                break;
            case 7:
                runCapteur = false;
                promptConsole("Retour au menu", VERT);
                cout << endl << endl;
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menuGestionCapteur

void menuGestionMesure(GestionMesure* gm, GestionCapteur* gc)
{
#ifdef MAP
    cout << "Appel à la méthode menuGestionMesure de <main>" << endl;
#endif
    string prompt("Veuillez choisir une des fonctionnalités suivantes :");
    string choice1("Afficher la liste des attributs");
    string choice2("Afficher toutes les données");
    string choice3("Trouver données similaires");
    string choice4("Consulter mesure(s)");
    string choice5("Calculer une moyenne de valeurs");
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
                cout<<gm->consulterMesure(gm->listeMesure)<<endl;
                break;
            case 3:

                break;
            case 4:
                paramDonnees(gc, gm);
                break;
            case 5:

                break;
            case 6:
                runMesure = false;
                promptConsole("Retour au menu", VERT);
                cout << endl << endl;
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menuGestionMesure

void gestionDesDecisions (Warning *wr, double valeur, string sensorId)
{
	string read;
	bool aucuneDecision = true;
	cout<<"Voulez vous qu'on vous propose une solution? (oui)"<<endl;
	cin>>read;
	if(read=="oui")
	{
		Decision decision_propose=wr->proposerDecision();
		if(decision_propose.getNote()>2)
		{
			bool* action = decision_propose.getAction();
			cout<<"---On vous propose---"<<endl;
			if(action[0]) cout<<"Alterner les voitures d'imatriculation paire ou impaire"<<endl;
			if(action[1]) cout<<"Transport en commun gratuit pour tous pendant 3 jours"<<endl;
			if(action[2]) cout<<"Favoriser le co-voiturage avec des payages gratuits"<<endl;
			if(action[3]) cout<<"Augmenter les prix des polluants"<<endl;
			aucuneDecision = false;
		} else cout<<"Aucune proposition ne peut etre faite a ce moment"<<endl;
	}
		if(aucuneDecision){
		cout<<"Voulez vous entrer une decision? (oui)"<<endl;
		cin>>read;
		if(read=="oui")
		{
			bool *action = new bool[4];
			cout<<"Alterner les voitures d'imatriculation paire ou impaire (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[0]=true;
			cout<<"Transport en commun gratuit pour tous pendant 3 jours (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[1]=true;
			cout<<"Favoriser le co-voiturage avec des payages gratuits (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[2]=true;
			cout<<"Augmenter les prix des polluants (oui)"<<endl;
			cin>>read;
			if(read=="oui") action[3]=true;
			Decision *laDecision = new Decision(action,sensorId);
			wr->entrerDecision(*laDecision,valeur);
		}
	}
}

/* MENU PRINCIPAL */

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
                menuGestionMesure(gm,gc);
                break;
            case 3:

                break;
            case 4:
                run = false;
                promptConsole("A bientôt", VERT);
                break;
        }
        cout << endl << endl;
    }
} //----- Fin de menu




////////// CODE TEST ///////////
/*
int nb_sensor = gc->listeCapteur.size();
double time = 0;
int j;
for (j = 0; j < i/2; j++) {
	int num = rand() % nb_sensor;
	std::string id = std::to_string(num);
	auto start = chrono::steady_clock::now();
	gm->getMesure(id);
	auto end = chrono::steady_clock::now();
	time = time + chrono::duration_cast<chrono::microseconds>(end - start).count();
}
time = time/(j);
cout << "Writing to file for n = " <<i<< "and average time is : "<<time<<endl;
myfile <<"microseconds: "<<time<<" | N: "<<i<< endl;
*/
