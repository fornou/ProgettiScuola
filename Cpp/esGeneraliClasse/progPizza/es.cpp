#include "libArray.h"

#define DIM 10
struct allenatore{
    string nome, cognome;
    int titoliVinti;
};

struct squadra{
    string nomeSq, coloreMaglia;
    int punteggio;
    allenatore al;
};

void scambia(squadra &sq, squadra &l2){
    squadra l3 = sq;
    sq = l2;
    l2 = l3;
}

void ordina(int n, squadra sq[]){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            if(sq[i].punteggio<sq[j].punteggio){
                scambia(sq[i], sq[j]);
            }
        }
    }
}

void inserisci(int n, squadra sq[]){
    for(int i = 0; i < n; i++){
        sq[i].nomeSq = in_parola_spazi("inserisci nome squadra", sq[i].nomeSq);
        sq[i].coloreMaglia = in_parola_spazi("inserisci colore maglia", sq[i].coloreMaglia);
        sq[i].punteggio = in_int("inserisci numero punteggio", sq[i].punteggio);
        sq[i].al.nome = in_parola("inserisci nome allenatore", sq[i].al.nome);
        sq[i].al.cognome = in_parola("inserisci cognome allenatore", sq[i].al.cognome);        
        sq[i].al.titoliVinti = in_int("inserisci titoli vinti", sq[i].al.titoliVinti); 
        cls();       
    }
}

void stampa(int n, squadra sq[]) {
    ordina(n, sq);
    cout << setw(25) << left << "Nome"
         << setw(25) << "Colore Maglia"
         << setw(10) << "Punteggio"
         << setw(25) << "Nome Allenatore"
         << setw(25) << "Cognome Allenatore"
         << setw(15) << "Titoli Vinti" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(25) << left << sq[i].nomeSq
             << setw(25) << sq[i].coloreMaglia
             << setw(10) << sq[i].punteggio
             << setw(25) << sq[i].al.nome
             << setw(25) << sq[i].al.cognome
             << setw(15) << sq[i].al.titoliVinti << endl;
    }
}

bool allConPuntMin(int n, squadra sq[]){
    bool trov = false;
    int ric = in_double("Numero punti:",ric);
    cout << "Allenatori con punti classifica minori di " << ric << ":"<< endl;
    for (int i = 0; i < n; i++){
        if (sq[i].punteggio < ric){
            cout << sq[i].al.cognome  << " " << sq[i].punteggio<< endl;
            trov = true;
        }   
    }
    return trov;
}

int numAlConTitolo(int n, squadra sq[]){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if ( sq[i].al.titoliVinti >= 1 ){
            cont ++;
        }   
    }
    return cont;
}

bool squConTit(int n, squadra sq[]){
    bool trov = false;
    int ric = in_double("Numero titoli:",ric);
    cout << "Squadre con allenatore con titoli maggiori di " << ric << ":"<< endl;
    for (int i = 0; i < n; i++){
        if (sq[i].al.titoliVinti > ric){
            cout << sq[i].nomeSq  << " " << sq[i].al.titoliVinti<< endl;
            trov = true;
        }   
    }
    return trov;
}

void stampaMenu(){
     cout << "____________________________________________________________________________________________\n\n"                     
        << "                                         MENU'         \n"
        << "____________________________________________________________________________________________\n\n"
        << "                             1) Inserimento dati Squadre\n"
        << "                    2) Classifica delle squadre con nome dell'allenatore\n"
        << "      3) Visualizzare cognome allenatori di squadre che hanno piu' di X punti in classifica\n"
        << "                4) Numero totale di allenatori che hanno vinto almeno un titolo\n"
        << "    5) Elenco delle squadre i cui allenatori che hanno vinto piu' di Y (preso in input) titoli.\n"
        << "                                        0) EXIT\n";
        
}

int main(){ 
    squadra sq[DIM];
    int s, n;
    bool t = false;
    
    do{
        cls();
        stampaMenu();
        if(!t){
            s = ins_in_range(s, 0, 1);
        }else{
             s = ins_in_range(s, 0, 5);
        }
        cls();
        switch (s){
            case 1:
                cout << "Inserimento dati Squadre:\n";
                n = newDimArray(n, DIM, "squadre"), s;
                inserisci(n, sq);
                t = true;
            break;

            case 2:
                cout << "Classifica delle squadre con nome dell'allenatore\n";
                stampa(n, sq);
            
                
            break;

            case 3:
                if(!allConPuntMin(n, sq)){
                    cout << "Non ci sono allenatori con punteggio minore di quello inserito\n";
                }
            break;

            case 4:
                cout << "Numero totale di allenatori che hanno vinto almeno un titolo\n";
                 cout << numAlConTitolo(n, sq);
            break;

            case 5:
                squConTit(n, sq);
            break;

            case 0: break;
                
            default:
                cout << "Non compreso\n";
            break;
        }
        cls();
    }while(s!=0);


}