#include <iostream>
#include "controllo-new.h"
using namespace std;

struct allenatore{
	string nome,cognome;
	int titoli;
};

struct squadra{
	string nome,colore;
	int punteggio;
	allenatore coach;
};

// FUNZIONE DI CREAZIONE DEL MENU' UTENTE
int Menu(void){
	setlocale(LC_ALL, "Italian");
	int scelta;
	do{
		system("CLS");
		cout << "\n\t************ Gestione fantacalcio ********* "<<endl<<endl;
		cout <<"\n\t ********** Men� programma ***********\n";
		cout << "\t 1. Inserimento dati Squadre "<<endl;
		cout << "\t 2. Classifica delle squadre con nome dell'allenatore "<<endl;
		cout << "\t 3. Visualizzare cognome allenatori di squadre con punti > X"<<endl;
		cout << "\t 4. Numero totale di allenatori che hanno vinto almeno un titolo"<<endl;
		cout << "\t 5. Elenco delle squadre con allenatori pi� di Y  titoli"<<endl;
		cout << "\t 6. Fine"<<endl<<endl;
		
 		string st="\t Inserire scelta (1, 2, 3, 4, 5  oppure 6)  :    ";
 		scelta=input_range(st,1,6);//controlla se input � nel range e se � un numero
	
	}while ((scelta < 1) || (scelta > 6));
	return scelta;
}

int inserisciDimensione(int max){
		int dim;
		string st="Quanti concorrenti partecipano alla gara? (1- " +to_string(max)+ ") :  ";
		dim=input_range(st,1,max);
		fflush(stdin);
		return dim;

}
void inserimento(squadra V[],int n){ 
	for(int i=0; i<n;i++){ 
		cout <<"--- Dati squadra "<<i+1<<"---"<<endl;
		cout<<"Inserire nome della squadra: ";
		getline(cin, V[i].nome);
		cout<<"Inserire colore della squadra: ";
		getline(cin, V[i].colore);
		cout<<"Inserire il punteggio"<<endl;
		V[i].punteggio=input_numero();
		//cin>>V[i].punteggio;
		fflush(stdin);
		cout<<"Inserire il nome dell'allenatore: ";
		getline(cin, V[i].coach.nome);
		cout<<"Inserire il cognome dell'allenatore: ";
		getline(cin, V[i].coach.cognome);
		cout<<"Inserire il numero di titoli dell'allenatore"<<endl;
		V[i].coach.titoli=input_numero();
		fflush(stdin);
		cout<<endl;
	}
}

void StampaAllenatoriSquadresup30(squadra V[],int n){ //
	for(int i=0; i<n;i++){ //
		if(V[i].punteggio>30){
		cout<<"---------------------"<<endl;	
		cout<<"|Cognome: "<<V[i].coach.cognome<<"|"<<endl;
		}
	}
	cout<<"---------------------"<<endl;
	cout<<endl<<endl;
}

int ContaAllenatorisup1(squadra V[],int n){ //
	int cont;
	for(int i=0; i<n;i++){ //
		if(V[i].coach.titoli>=1){
			cont++;
		}
	}
	return cont;
}

void stampaClassifica(const squadra v[], int dim){
	cout<<"Nome squadra"<<"\t"<<"Punti"<<"\t"<<"Allenatore "<<endl;
	for(int i=0;i<dim;i++ ){
		cout<< v[i].nome<<"\t"<<v[i].punteggio<<"\t"<<v[i].coach.cognome<<" " << v[i].coach.nome<<endl;		
	}
	cout<<endl;
}

void stampaAllenatorisup1titolo(int num){
	cout<<"Il numero di allenatori che hanno vinto almeno un titolo � : "<<num<<endl<<endl<<endl;
}


void StampaAllenatorisup3(squadra V[],int n){ 
	cout<<"Squadra \t";
	cout<<"Colore \t";
	cout<<"Punti \t";
	cout<<"Allenatore \t";
	cout<<"Titoli"<<endl;
	for(int i=0; i<n;i++){ 
		if(V[i].coach.titoli>3){
			cout<<V[i].nome<<"\t";
			cout<<V[i].colore<<"\t";
			cout<<V[i].punteggio<<"\t";
			cout<<V[i].coach.cognome<<"	";
			cout<<V[i].coach.nome<<"\t";
			cout<<V[i].coach.titoli<<endl;
		}
	}
}

int main(){
	setlocale(LC_ALL, "Italian");
	int scelta;
	int conta;	
	bool dati_ok=false;
	int n=10; //numero di squadre massima da gestire
	squadra V[n];
	do{
	    scelta = Menu();
	    switch (scelta){
		case 1: 
	    		system("CLS");
				cout<<"Numero massimo di squadre che si vuole gestire:"<<endl;
				n=inserisciDimensione(n);
				fflush(stdin);
				cout << "-- Inserimento dati delle Squadre -- " << endl;
				inserimento(V,n);						  
				dati_ok=true;
		  		break;
	      	case 2: 
    			system("CLS");	  
				cout << " Classifica delle squadre con nome dell'allenatore "<<endl;				    	
    			if (dati_ok==true){
					stampaClassifica(V, n)  ; 				
				}else{
					cout <<"Non sono stati inseriti Dati"<<endl;
				}
		  		break;
	      	case 3: 
    			system("CLS");		      	
				cout<<"Elenco degli allenatori di squadre superiori a 30 punti:"<<endl; 
    			if (dati_ok==true){
					StampaAllenatoriSquadresup30(V,n);				
				}else{
					cout <<"Non sono stati inseriti Dati"<<endl;
				}
		  		break;
	      	case 4: 
    			system("CLS");	      	
				cout << "Totale di allenatori che hanno vinto almeno un titolo"<<endl;
    			if (dati_ok==true){
					conta=ContaAllenatorisup1(V,n);
					stampaAllenatorisup1titolo(conta);				
				}else{
					cout <<"Non sono stati inseriti Dati"<<endl;
				}				
			  	break;
		    case 5: 
	    		system("CLS");	      
				cout << "Elenco delle squadre con allenatori pi� di Y  titoli"<<endl;
    			if (dati_ok==true){
					cout<<"Le squadre con allenatore possessore di piu' di 3 titoli: "<<endl;
					StampaAllenatorisup3(V,n);				
				}else{
					cout <<"Non sono stati inseriti Dati"<<endl;
				}				
				break;
	      case 6:
		       	 cout <<"\n\nGrazie per aver utilizzato il programma... \n\n";
		}
		system("PAUSE");
	    system("CLS");		
	}while (scelta != 6);	
	return 0;
}
