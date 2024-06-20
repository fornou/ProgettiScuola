#include "../Libreries/libArray.h"
struct atleta
{
    string nome, cognome;
    int numPettorina;
    double tempo;
};
#define DIM 50

void inserisci(int n, atleta l1[]){
    bool uguale;
    for(int i = 0; i < n; i++){
        l1[i].nome = in_parola_spazi("inserisci nome", l1[i].nome);
        l1[i].cognome = in_parola_spazi("inserisci cognome", l1[i].cognome);
        do{
            uguale = false;
            l1[i].numPettorina = in_int("inserisci numero pettorina", l1[i].numPettorina);
            for(int j = 0; j < i; j++){
                if(l1[i].numPettorina == l1[j].numPettorina){
                    cout << "rinserisci, pettorina gia' esistente\n";
                    uguale = true;
                }
            }
        }while(uguale);
        l1[i].tempo = in_double("inserisci il tempo", l1[i].tempo);
        cls();
    }
}

void stampa(int n, atleta l1[]){
    cout << setw(25) << left << "Nome"
         << setw(25) << "Cognome"
         << setw(10) << "N pettorina"
         << setw (10) << "Tempo" << endl;
    // Stampare i dati dei libri
    for(int i = 0; i < n; i++) {
        cout << setw(25) << left << l1[i].nome
             << setw(25) << l1[i].cognome
             << setw(10) << l1[i].numPettorina
             << setw(10) << l1[i].tempo << endl;
    }
}

void stampaPod( atleta l1[]){
    stampa(3, l1);
    cout << "Il vincitore è: " << l1[0].cognome << " " << l1[0].nome << endl;
}

void scambia(atleta &l1, atleta &l2){
    atleta l3 = l1;
    l1 = l2;
    l2 = l3;
}

void ordina(int n, atleta l1[]){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            if(l1[i].tempo>l1[j].tempo){
                scambia(l1[i], l1[j]);
            }
        }
    }
}

bool cercaNPettorina(int n, atleta l1[]){
    bool trov = false;
    int ric = in_int(ric);
    for (int i = 0; i < n; i++){
        if (l1[i].numPettorina == ric){
            cout << "Numero pettorina ricercato:" << ric << endl;
            cout << l1[i].nome << " " << l1[i].cognome << " " << i << endl;
            trov = true;
        }   
    }
    return trov;
}

bool cercaSecondi(int n, atleta l1[]){
    bool trov = false;
    int ric = in_double(ric);
    cout << "Numero secondi ricercato:" << ric << endl;
    for (int i = 0; i < n; i++){
        if (l1[i].tempo < ric){
            cout << l1[i].nome << " " << l1[i].cognome << " " << l1[i].numPettorina << " " << l1[i].tempo << " " << (i+1) << endl;
            trov = true;
        }   
    }
    return trov;
}

void stampaMenu(){
     cout << "_______________________\n\n"                     
          << "         MENU'         \n"
          << "_______________________\n\n"
          << "1- stampa classifica totale\n"
          << "2- podio\n"
          << "3- cerca atleta tramite pettorina\n"
          << "4- cerca atleti con tempo minore\n"
          << "5- EXIT\n"
          << "Effettua la tua scelta:\n";
}

int main(){
    cls();
    int s,  n = newDimArray(n, DIM, "atleti");
    atleta l1[DIM];
    cls();
    inserisci(n, l1);
    ordina(n, l1);
    cls();
    do{
        stampaMenu(); 
        switch (in_int(s))
        {
            cls();
            case 1:
                cout << "Classifica totale\n";
                stampa(n, l1);
            break;

            case 2:
                cout << "Podio\n";
                stampaPod(l1);
            break;

            case 3:
                cout << "Cerca atleta tramite numero di pettorina\n";
                if(!cercaNPettorina(n, l1)){
                    cout << "Non esiste una pettorina con questo numero\n";
                }
            break;

            case 4:
                cout << "Cerca atleti tramite tempo\n";
                if(!cercaSecondi(n, l1)){
                    cout << "Non esiste una persona con un tempo minore\n";
                }
            break;

            case 5:break;
                
            default:
                cout << "Non compreso\n";
            break;
        }
        pause();
        cls();
    }while(s!=5);
    
}