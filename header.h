#ifndef PRO_H
#include<iostream>
using namespace std;
typedef struct{
	int jour;
	int mois;
	int annee;
	int heure;
}dates;
typedef struct{
	int jour;
	int mois;
	int annee;
}datep;
class professeur{
	int id_prof;
	string nom_prof;
	string prenom_prof;
	string adresse_prof;
	string niveau;
	double salaire;
	datep date_affectation;
	public:
		professeur();
		void affichage();
		void saisie();
		int getid();
		string getnom();
		string getprenom();
		string getadresse();
		string getniveau();
		double getsalaire();
		datep getdate();
		void setid(int i);
		void setnom(string i);
		void setprenom(string i);
		void setadresse(string i);
		void setniveau(string i);
		void setsalaire(double i);
		void setdate(datep i);
		
};
class etudiant{
	int id_etudiant;
	string nom_etudiant;
	string prenom_etudiant;
	string adresse_etudiant;
	int age;
	public:
		etudiant(etudiant& e);
		etudiant();
		void affichage();
		void saisie();
		int getid();
		string getnom();
		string getprenom();
		string getadresse();
		int getage();
		void setid(int i);
		void setnom(string n);
		void setprenom(string n);
		void setadresse(string ad);
		void setage(int n);
		bool compare(etudiant e);
};
class module{
	static int count;
	int id_module;
	etudiant *E;
	int Nombre_etudiant;
	string nom_module;
	professeur *p;
	dates date_pl;
	public:
		void saisie();
		module();
		module(int k,etudiant *f,int n,string m,professeur *r,dates d);
		bool verifie(etudiant e);
		int ajouter_etudiant(etudiant e);
		void modifier_nom_module(string n);
		void affiche_etud_plus_20ans();
		dates calcule_periode();
		void supprimer_etudiant(etudiant e);
		void afficher_module();
		int getid();
		string getnom();
		void setprofesseur(professeur *k);
		module(module& m);
};
bool tester_existance_module(module *T,int n,module r);
void ajoute_module(module *T,int &n,module r);
void modifier_nom_module_externe(module *T,int n,module &m,string nn);
void modifier_professeur_module(module *T,int n,module &m,professeur *o);
void supprimer_module(module *T,int &n,module m);
void afficher_tableau_module(module *T,int n);
void retirer_etudiant_module(module* T,int n,module m,etudiant e);
void module_depasse_10ans(module *T,int n);


#endif