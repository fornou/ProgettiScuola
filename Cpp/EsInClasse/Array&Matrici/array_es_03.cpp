// Programma scritto da  Armando Valentino
// tavola pitagorica
#include <iostream>
using namespace std;
//#define dim 10
#define riga 10
#define colonna 10
void calcolaTavola(int tv[][colonna], int r,int c){
	for (int i=0; i<r;i++){
		for (int k=0; k<c;k++){
			tv[i][k]=(i+1)*(k+1);
		}
	}
}
void stampa(int tv[][colonna], int r,int c){
	for (int i=0; i<r;i++){
		for (int k=0; k<c;k++){
			cout <<tv[i][k];
			cout <<"\t";
		}
		cout <<"\n";
	}
}
int main(){
	setlocale(LC_ALL,"Italian");
//	int riga=10;
//	int colonna=10;
	int tavola[riga][colonna];
	calcolaTavola(tavola,riga,colonna);
	stampa(tavola,riga,colonna);
	return 0;
}

