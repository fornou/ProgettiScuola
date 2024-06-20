#include "libArray.h"
#define colonna 5
#define riga 40

void caricaVoti(int tv[][colonna], int r, int c){
	srand(time(0));
	for (int i=0; i<r;i++){
		for (int k=0; k<c;k++){
			tv[i][k]= rand_in_range(0, 10);
		}
	}
}

void stampaVoti(int tv[][colonna], int r,int c){
	for (int i=0; i<r;i++){
		cout << "I voti studente " << i << ": ";
		for (int k=0; k<c;k++){
			cout <<tv[i][k];
			cout <<" ";
		}
		cout <<"\n________________\n";
	}
}

void calcMedia(int tv[][colonna], int r,int c, double media[]){
	int cont;
	for (int i=0; i<r;i++){
		cont = 0;
		for (int k=0; k<c;k++){
			if(tv[i][k] == 0){cont++;}
			media[i] += tv[i][k];
		}
		media[i]/=(colonna-cont);
	}
    
}

void calcSuffic(int tv[][colonna], int r,int c, int s[]){
	int cont;
	for (int i=0; i<r;i++){
		cont = 0;
		for (int k=0; k<c;k++){
			if(tv[i][k] != 0 && tv[i][k]>5)
				cont++;
		}
		s[i] = cont;
	}
	
}

void stampaValori(int r,double media[],int s[]){
    for (int i=0; i<r;i++){
		cout << "Studente " << i <<" -> Esami superati: " << s[i] << " | Media: " << media[i] << endl;	
	}
	 
}

int main(){
	setlocale(LC_ALL,"Italian");
    double media[riga];
	int sufficienti[riga];
	int tavola[riga][colonna];

	int n = newDimArray(n, riga);
	caricaVoti(tavola,n,colonna);
	stampaVoti(tavola,n,colonna);
	pause();
    calcMedia(tavola,n,colonna, media);
	calcSuffic(tavola,n,colonna, sufficienti);
    stampaValori(n, media, sufficienti);
    
	return 0;
}


