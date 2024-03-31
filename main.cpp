#include "pro.h"

main(){

int h;
cout<<"1-professeur"<<endl<<"2-etudiant"<<endl<<"3-module"<<endl<<"4-table module"<<endl;
cin>>h;
switch (h){
	case 1:
		{
			int o=0;
		professeur p;
		p.saisie();
		cout<<"1-afficher le professeur"<<endl;
		cin>>o;
		if(o==1)
		{
			p.affichage();
		}
		break;}
	case 2:
		{
		int o=0;
		etudiant e1,e2;
		cout<<"pour comparer deux etudiants vous devez saisir deux etudiants :"<<endl;
		cout<<"pour le premier etudiant :"<<endl;
		e1.saisie();
		cout<<"pour le deuxieme etudiant :"<<endl;
		e2.saisie();
		cout<<"1-afficher les etudiants"<<endl<<"2-comparer les etudiants"<<endl;
		cin>>o;
		if(o==1)
		{
			e1.affichage();
		}
		else if(o==2)
		{
			if(e1.compare(e2))
			cout<<"les etudiants sont identiques."<<endl;
			else
			cout<<"les etudiants sont differents."<<endl;
		}
		break;	
		}
	case 3:
		{
		module m;
		m.saisie();
		int y=0;
		cout<<"1-verifier etudiant :"<<endl<<"2-ajouter etudiant :"<<endl<<"3-modifier nom du module :"<<endl<<"4-afficher les etudiants ages plus de 20ans :"<<endl<<"5-calculer la periode :"<<endl<<"6-supprimer un etudiant :"<<endl<<"7-afficher le module :"<<endl;
		cin>>y;
		switch (y){
			case 1:
				{
					etudiant w;
					w.saisie();
					if(m.verifie(w))
					cout<<"etudiant existe ."<<endl;
					else
					cout<<"etudiant n'existe pas !!!"<<endl;
					break;
				}
			case 2:
				{
					etudiant w;
					w.saisie();
					if(m.ajouter_etudiant(w)==1)
					{
						cout<<"l'etudiant deja existe !!!"<<endl;
					}
					else if(m.ajouter_etudiant(w)==(-1))
					{
						cout<<"le module est plein !!!"<<endl;
					}
					else
					cout<<"etudiant ajouter averc succes ."<<endl;
					break;
				}
				case 3:
					{
						string j;
						cout<<"donnez le nouveau nom :"<<endl;
						cin>>j;
						m.modifier_nom_module(j);
						break;
					}
				case 4:
					{
						m.affiche_etud_plus_20ans();
						break;
					}
				case 5:
					{
						dates d;
						d=m.calcule_periode();
						cout<<d.annee<<"/"<<d.mois<<"/"<<d.jour<<" et "<<d.heure<<"heures ."<<endl;
						break;
					}
				case 6:
					{
						etudiant w;
						w.saisie();
						m.supprimer_etudiant(w);
						break;
					}
				case 7:
					{
						m.afficher_module();
						break;
					}
				default:
				{
				cout<<"choix incorect !!!"<<endl;
					break;	
					}	
		}
		break;	
		}
		case 4:
			{
				module *m;
				int n;
				cout<<"entrez le nombre des modules :"<<endl;
				cin>>n;
				m=(module*)new module[n];
				for(int i=0;i<n;i++)
				{
					m[i].saisie();
				}
				int p=0;
				cout<<"1-tester l'existance"<<endl<<"2-ajouter module"<<endl<<"3-modifier nom du module"<<endl<<"4-modifier professeur"<<endl<<"5-supprimer module"<<endl<<"6-afficher tableau module"<<endl<<"7-retirer etudiant du module"<<endl<<"8-afficher les modules qui depasse 10 ans"<<endl;
				cin>>p;
				switch (p){
					case 1:
						{
							module t;
							cout<<"donner le module pour tester l'existance "<<endl;
							t.saisie();
							if(tester_existance_module(m,n,t))
							cout<<"module existe"<<endl;
							else
							cout<<"module n'existe pas"<<endl;
							break;
						}
						
					case 2:
						{
							module t;
							cout<<"donner le module pour ajouter "<<endl;
							t.saisie();
							if(tester_existance_module(m,n,t))
							cout<<"module existe"<<endl;
							else
							{
								ajoute_module(m,n,t);
								cout<<"module ajouter avec succes"<<endl;
							}
							break;
						}
						
					case 3:
						{
							module t;
							cout<<"donner le module "<<endl;
							t.saisie();
							if(tester_existance_module(m,n,t))
							{
								string nom;
								cout<<"donner le nouveau nom"<<endl;
								cin>>nom;
								modifier_nom_module_externe(m,n,t,nom);
								cout<<"nom modifier avec succes"<<endl;
							}
							else
							{
								cout<<"module n'existe pas !!!"<<endl;
							}
							break;
						}
						
					case 4:
						{
							professeur *l,k;
							module t;
							t.saisie();
							cout<<"donner le professeur a modifier"<<endl;
							k.saisie();
							l=&k;
							modifier_professeur_module(m,n,t,l);
							break;
						}
						
					case 5:
						{
							module t;
							
							cout<<"donner le module a supprimer"<<endl;
							t.saisie();
							supprimer_module(m,n,t);
							break;
						}
						
					case 6:
						{
							afficher_tableau_module(m,n);
							break;
						}
						
					case 7:
						{
							etudiant q;
							module t;
							cout<<"donner l'etudiant a retirer "<<endl;
							q.saisie();
							cout<<"donner le module"<<endl;
							t.saisie();
							retirer_etudiant_module(m,n,t,q);
							cout<<"etudiant retirer avec succes ."<<endl;
							break;
						}
						
					case 8:
						{
							module_depasse_10ans(m,n);
							break;
						}
						
					default:
						{
							cout<<"choix incorecte !!!"<<endl;
							break;	
						}	
				}
				break;
			}
	default:
		cout<<"vous devez choisir 1,2 ou 3 ."<<endl;
		break;
}
}