#include "pro.h"

int module::count=0;

professeur::professeur()
{
	id_prof=0;
	nom_prof="";
	prenom_prof="";
	adresse_prof="";
	niveau="";
	salaire=0;
	date_affectation.annee=0;
	date_affectation.jour=0;
	date_affectation.mois=0;
}
void professeur::affichage()
{
		cout<<"professeur id : "<<id_prof<<endl<<"professeur nom : "<<nom_prof<<endl<<"professeur prenom : "<<prenom_prof<<endl<<"professeur adresse : "<<adresse_prof<<endl<<"professeur niveau : "<<niveau<<endl<<"professeur salaire : "<<salaire<<endl<<"professeur date d'afectation : "<<date_affectation.annee<<"/"<<date_affectation.mois<<"/"<<date_affectation.jour<<endl;		
}
void professeur::saisie()
{
	cout<<"veuillez saisir le professeur :"<<endl;
		cout<<"id :"<<endl;
		cin>>id_prof;cin.ignore();
		cout<<"nom :"<<endl;
		cin>>nom_prof;cin.ignore();
		cout<<"prenom :"<<endl;
		cin>>prenom_prof;cin.ignore();
		cout<<"adresse :"<<endl;
		cin>>adresse_prof;cin.ignore();
		cout<<"niveau :"<<endl;
		cin>>niveau;cin.ignore();
		cout<<"salaire :"<<endl;
		cin>>salaire;cin.ignore();
		cout<<"la date d'affectation(jour/mois/annee) :"<<endl;
		cin>>date_affectation.jour;cin.ignore();
		cin>>date_affectation.mois;cin.ignore();
		cin>>date_affectation.annee;cin.ignore();
}

		int professeur::getid()
		{
			return id_prof;
		}
		string professeur::getnom()
		{
			return nom_prof;
		}
		string professeur::getprenom()
		{
			return prenom_prof;
		}
		string professeur::getadresse()
		{
			return adresse_prof;
		}
		string professeur::getniveau()
		{
			return niveau;
		}
		double professeur::getsalaire()
		{
			return salaire;
		}
		datep professeur::getdate()
		{
			return date_affectation;
		}
		void professeur::setid(int i)
		{
			id_prof=i;
		}
		void professeur::setnom(string i)
		{
			nom_prof=i;
		}
		void professeur::setprenom(string i)
		{
			prenom_prof=i;
		}
		void professeur::setadresse(string i)
		{
			adresse_prof=i;
		}
		void professeur::setniveau(string i)
		{
			niveau=i;
		}
		void professeur::setsalaire(double i)
		{
			salaire=i;
		}
		void professeur::setdate(datep i)
		{
			date_affectation.annee=i.annee;
			date_affectation.jour=i.jour;
			date_affectation.mois=i.mois;
		}
		
		
		etudiant::etudiant(etudiant& e)
		{
			id_etudiant=e.id_etudiant;
			nom_etudiant=e.nom_etudiant;
			prenom_etudiant=e.prenom_etudiant;
			adresse_etudiant=e.adresse_etudiant;
		}
		etudiant::etudiant()
		{
			id_etudiant=0;
			nom_etudiant="";
			prenom_etudiant="";
			adresse_etudiant="";
			age=0;
		}
		void etudiant::affichage()
		{
			cout<<"etudiant id:"<<id_etudiant<<"etudiant nom:"<<nom_etudiant<<"etudiant prenom:"<<prenom_etudiant<<"etudiant adresse:"<<adresse_etudiant<<"etudiant age:"<<age<<endl;
		}
		void etudiant::saisie()
		{
			cout<<"veuillez saisir l'etudiant : "<<endl;
		cout<<"id :"<<endl;cin>>id_etudiant;cin.ignore();
		
		cout<<"nom :"<<endl;cin>>nom_etudiant;cin.ignore();
		                                          
		cout<<"prenom :"<<endl;cin>>prenom_etudiant;cin.ignore();
		
		cout<<"adresse :"<<endl;cin>>adresse_etudiant;cin.ignore();
		
		cout<<"age :"<<endl;cin>>age;cin.ignore();
		
		}
		int etudiant::getid()
		{
			return id_etudiant;
		}
		string etudiant::getnom()
		{
			return nom_etudiant;
		}
		string etudiant::getprenom()
		{
			return prenom_etudiant;
		}
		string etudiant::getadresse()
		{
			return adresse_etudiant;
		}
		int etudiant::getage()
		{
			return age;
		}
		void etudiant::setid(int i)
		{
			id_etudiant=i;
		}
		void etudiant::setnom(string n)
		{
			nom_etudiant=n;
		}
		void etudiant::setprenom(string n)
		{
			prenom_etudiant=n;
		}
		void etudiant::setadresse(string ad)
		{
			adresse_etudiant=ad;
		}
		void etudiant::setage(int n)
		{
			age=n;
		}
		bool etudiant::compare(etudiant e)
		{
			if(id_etudiant==e.id_etudiant)
			return true;
			else
			return false;
		}
		
		
bool module::verifie(etudiant e)
		{
			for(int i=0;i<count;i++)
			{
				if(E[i].getid()==e.getid())
				return true;
			}
			return false;
		}
int module::ajouter_etudiant(etudiant e)
		{
			if(count<Nombre_etudiant)
			{
				for(int i=0;i<count;i++)
				{
					if(E[i].getid()==e.getid())
					return 1;
				}	
			}
			else
			{
				return -1;
			}
			E=(etudiant*)realloc(E,(count+1)*sizeof(etudiant));
			E[count].setadresse(e.getadresse());
			E[count].setage(e.getage());
			E[count].setid(e.getid());
			E[count].setnom(e.getnom());
			E[count].setprenom(e.getprenom());
			count++;
			return 0;
		}
		void module::modifier_nom_module(string n)
		{
			nom_module=n;
		}
		void module::affiche_etud_plus_20ans()
		{
			for(int i=0;i<count;i++)
			{
				if(E[i].getage()>20)
				{
					cout<<"id :"<<E[i].getid()<<" || nom :"<<E[i].getnom()<<" || prenom :"<<E[i].getprenom()<<" || age :"<<E[i].getage()<<endl;
				}
			}
		}
		dates module::calcule_periode()
		{
			dates d, j;
			cout<<"donner la date d'aujoud'hui (annee/mois/jour/heur):"<<endl;
			cin>>d.annee;
			cin>>d.mois;
			cin>>d.jour;
			cin>>d.heure;
			j.annee=d.annee-date_pl.annee;
			j.heure=d.heure-date_pl.heure;
			j.jour=d.jour-date_pl.jour;
			j.mois=d.mois-date_pl.mois;
			return j;
		}
		void module::supprimer_etudiant(etudiant e)
		{
			for(int i=0; i<count;i++)
			{
				if(E[i].getid()==e.getid())
				{
					for(int j=i;j<count-1;j++)
					{
						E[i]=E[i+1];
					
					}
					E=(etudiant*)realloc(E,(count-1)*sizeof(etudiant));
					cout<<"l'etudiant a ete supprimer du module avec succes ."<<endl;
					return;
				}
			}
			cout<<"l'etudiant ne fait pas partie du module !!!"<<endl;
		}
		void module::afficher_module()
		{
			cout<<"l'id du module est :"<<endl;
			cout<<id_module<<endl;
			
			cout<<"les etudiants sont :"<<endl;
			for(int i=0;i<count;i++){
			cout<<"ID : ";
				cout<<E[i].getid()<<"||";
			cout<<"nom : ";
				cout<<E[i].getnom()<<"||";
			cout<<"prenom : ";
				cout<<E[i].getprenom()<<"||";
			cout<<"age : ";
				cout<<E[i].getage()<<"||";
			cout<<"adresse : ";
				cout<<E[i].getadresse()<<endl;
			}

				
			cout<<"les informations du professeur sont :"<<endl;
			cout<<"ID : "<<p->getid()<<"||";
			
			cout<<"nom : "<<p->getnom()<<"||";
			
			cout<<"prenom : "<<p->getprenom()<<"||";
			
			cout<<"niveau : "<<p->getniveau()<<"||";
			
			cout<<"salaire : "<<p->getsalaire()<<"||";
			cout<<"date : "<<p->getdate().annee<<"/"<<p->getdate().mois<<"/"<<p->getdate().jour<<"||";
			cout<<endl;
			cout<<"la date du lancement du module est :"<<endl<<date_pl.jour<<"/"<<date_pl.mois<<"/"<<date_pl.annee<<" a "<<date_pl.heure<<endl;
		}
		int module::getid()
		{
			return id_module;
		}
		string module::getnom()
		{
			return nom_module;
		}
		void module::setprofesseur(professeur *k)
		{
			p=k;
		}
		module::module(module &m)
		{
			id_module=m.id_module;
			for(int i=0;i<count;i++)
			{
				E[i]=m.E[i];
			}
			Nombre_etudiant=m.Nombre_etudiant;
			nom_module=m.nom_module;
			p=m.p;
			date_pl.annee=m.date_pl.annee;
			date_pl.heure=m.date_pl.heure;
			date_pl.jour=m.date_pl.jour;
			date_pl.mois=m.date_pl.mois;
		}
		module::module(){
		id_module=0;
		E=NULL;
		Nombre_etudiant=0;
		nom_module=" ";
		p=NULL;
		date_pl.annee=0;
		date_pl.heure=0;
		date_pl.jour=0;
		date_pl.mois=0;
		count++;
		}
		module::module(int k,etudiant *f,int n,string m,professeur *r,dates d){
			id_module=k;
			E=(etudiant*)new etudiant[n];
			for(int i=0;i<n;i++)
			{
				E[i]=f[i];	
			}
			Nombre_etudiant=n;
			nom_module=m;
			p=r;
			date_pl.annee=d.annee;
			date_pl.heure=d.heure;
			date_pl.jour=d.jour;
			date_pl.mois=d.mois;
			count=n;
		}
		void module::saisie()
		{
			cout<<"veulliez remplir le module :"<<endl;
		
		cout<<"id :"<<endl;
		cin>>id_module;
		
		
		cout<<"nom du module :"<<endl;
		cin>>nom_module;
		p=(professeur*)new professeur;
		p->saisie();
		cout<<"date du prmier lancement du module(jour/mois/annee/heur) :"<<endl;
		cin>>date_pl.jour;
		cin>>date_pl.mois;
		cin>>date_pl.annee;
		cin>>date_pl.heure;
		cout<<"nombre d'etudiants :"<<endl;
		cin>>Nombre_etudiant;
		
		E=(etudiant*)new etudiant[Nombre_etudiant];
		cout<<"veuillez saisir les etudiants :"<<endl;
		for(int i=0;i<Nombre_etudiant;i++)
		{
			cin.ignore();
			E[i].saisie();
		}
		}
		
bool tester_existance_module(module *T,int n,module r)
{
	for(int i=0;i<n;i++)
	{
		if(T[i].getid()==r.getid())
		return true;
	}
	return false;
}
void ajoute_module(module *T,int &n,module r)
{
	if(tester_existance_module(T,n,r))
	cout<<"ce module deja existe !!!"<<endl;
	else
	{
		T=(module*)realloc(T,(n+1)*sizeof(module));
		T[n]=r;
		n++;
	}
}
void modifier_nom_module_externe(module *T,int n,module &m,string nn)
{
	for(int i=0;i<n;i++)
	{
		if(T[i].getid()==m.getid())
		{
			m.modifier_nom_module(nn);
			cout<<"le nouveau nom est : "<<m.getnom()<<endl;
			return;
		}
	}
	cout<<"ce module n'existe pas dans ce tableau !!!"<<endl;
}
void modifier_professeur_module(module *T,int n,module &m,professeur *o)
{
	for(int i=0;i<n;i++)
	{
		if(T[i].getid()==m.getid())
		{
			m.setprofesseur(o);
			cout<<"professeur modifier avec succes ."<<endl;
			return;
		}
	}
	cout<<"professeur n'existe pas !!!"<<endl;
}
void supprimer_module(module *T,int &n,module m)
{
	for(int i=0;i<n;i++)
	{
		if(T[i].getid()==m.getid())
		{
			for(int j=i;j<n-1;j++)
			{
				T[i]=T[i+1];
			}
			n--;
			return;
		}
	}
	cout<<"ce module n'existe pas !!!"<<endl;
}
void afficher_tableau_module(module *T,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"module "<<i+1<<" : "<<endl;
		T[i].afficher_module();
	}
}
void retirer_etudiant_module(module* T,int n,module m,etudiant e)
{
	for(int i=0;i<n;i++)
	{
		if(T[i].getid()==m.getid())
		{
			T[i].supprimer_etudiant(e);
			cout<<"etudiant supprimer avec succes ."<<endl;
			return;
		}
	}
	cout<<"ce module n'existe pas !!!"<<endl;
}
void module_depasse_10ans(module *T,int n)
{
	int y=0;
	for(int i=0;i<n;i++)
	{
		if(T[i].calcule_periode().annee>10||(T[i].calcule_periode().annee==10 && T[i].calcule_periode().heure>0)||(T[i].calcule_periode().annee==10 && T[i].calcule_periode().jour>0)||(T[i].calcule_periode().annee==10 && T[i].calcule_periode().mois>0))
		{
			T[i].afficher_module();
			cout<<endl;
			y++;
		}
	}
	if(y==0)
	{
		cout<<"aucun module ne depasse 10ans depuis sa date de lancement !!!"<<endl;
	}
}