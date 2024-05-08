#include "libArray.h"
#define dimAuto 10 

struct Persona{
    string nome, cognome;
};

struct Auto{
    string marca;
    int cilindrata, annoImmatricolazione;
    Persona p;
};


//_________________________________________________________________


//Punto 1:

//Inserimento dati veicolo
void inserisciAuto(Auto a[], int i){
    cout << "Inserimento Auto:\n";
    a[i].marca = in_parola_spazi("inserisci marca ", a[i].marca);
    a[i].annoImmatricolazione = in_int("inserisci anno immatricolazione ", a[i].annoImmatricolazione);
    a[i].cilindrata = in_double("inserisci cilindrata", a[i].cilindrata);
    a[i].p.nome = in_parola_spazi("inserisci nome possessore",a[i].p.nome);
    a[i].p.cognome = in_parola_spazi("inserisci cognome possessore",a[i].p.cognome);
    cls();
}
//Caricamento di n veicoli
void caricaAuto(Auto a[], int numAuto){
    for (int i = 0; i < numAuto; i++){
        inserisciAuto(a, i);
    }
}


//_________________________________________________________________

//                         Punto 2:

//Ottiene cognome tramite posizione
string getCognomeByPos(Auto a[], int pos){
    return a[pos].p.cognome;
}
//Stampa cognomi possessori con auto di cilindrata > 1500
bool stampaAutoCil_1500(Auto a[],int n){
    bool trov = false;
    cout << "Auto con cilindrata superiore di 1500: "<< endl;
    for (int i = 0; i < n; i++){
        if (a[i].cilindrata > 1500){
            cout << getCognomeByPos(a, i) << endl;
            trov = true;
        }   
    }
    return trov;
}


//_________________________________________________________________

//                         Punto 3:

//Stampa numero auto immatricolate in un anno specifico
int getNumAutoAnnoMin(Auto a[],int n){
    int numAuto = 0;
    int annoRic = in_int(annoRic);
    for (int i = 0; i < n; i++){
        if (a[i].annoImmatricolazione == annoRic){
            numAuto ++;
        }   
    }
    return numAuto;
}


//_________________________________________________________________

//                         Punto 4:

//Effettua lo scambio 
void scambia(Auto &a1, Auto &a2){
    Auto a3 = a1;
    a1 = a2;
    a2 = a3;
}
//Ordina tabella per anno di immatricolazione
void ordina(Auto a[], int n){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            if(a[i].annoImmatricolazione > a[j].annoImmatricolazione ){
                scambia(a[i], a[j]);
            }
        }
    }
}
//Stampa della tabella  marca,cilindrata, anno di immatricolazione, nome e cognome
void stampaAuto(Auto a[], int n){
    cout << "Marca\t" << "Cilindrata\t" << "Anno\t" << "Nome" 
    << "Cognome " << endl;
    for (int i = 0; i < n; i++){
        cout << a[i].marca << "\t" << a[i].cilindrata << "\t" 
             << a[i].annoImmatricolazione << "\t" << a[i].p.nome << "\t" 
             << a[i].p.cognome << endl;
    }
}


//_________________________________________________________________

//                         Punto 5:

//Controlla che l'anno non sia già passato
bool isAnnoPresente(Auto a[], int n, int annoAttuale){
    bool t = false;
    for (int i = 0; i < n; i++){
        if(a[i].annoImmatricolazione == annoAttuale){
            t = true;
        }
    }
    return t;
}
//Stampa dati auto tramite l'anno
void printDataAutoByAnno(Auto a[], int n, int annoRic){
    for (int i = 0; i < n; i++){
        if (a[i].annoImmatricolazione == annoRic){
            cout << a[i].marca << "," << a[i].cilindrata << "," << a[i].p.nome << ","  << a[i].p.cognome << endl;
        }   
    }
}
//Stampa formato richiesto
void stampaAutoPerAnno(Auto a[], int n){
    cout << "Auto Immatricolate e Vendute "<< endl;
    for (int i = 0; i < n; i++){
        if(!isAnnoPresente(a, i, a[i].annoImmatricolazione)){
            cout << a[i].annoImmatricolazione << ":" << endl;
            printDataAutoByAnno(a, n, a[i].annoImmatricolazione);
        }
    }
}


//_________________________________________________________________

//              Stampa menu di scelta iniziale

void stampaScelte(){
    cout <<  "_________________________________\n\n"                     
        <<   "              MENU'         \n"
        <<   "_________________________________\n\n"
        <<   "  1) Inserimento Auto\n"
        <<   "  2) Cognome con cilindrata>1500\n"
        <<   "  3) N auto immatricolate in anno X \n"
        <<   "  4) Ordina per anno\n"
        <<   "  5) Stampa auto immatricolate\n"
        <<   "  0) EXIT\n"
        <<   "__________________________________\n";
        
}

main(){
    int s, numAuto;
    bool t = false;
    Auto autoMobili[dimAuto];

    do{
        cls();
        stampaScelte();
        if(!t){
            s = ins_in_range(s, 0, 1);
        }else{
             s = ins_in_range(s, 0, 8);
        }
        cls();
        switch (s){
            case 1:
                numAuto = newDimArray(numAuto, dimAuto, "auto");
                cls();
                caricaAuto(autoMobili, numAuto);
                t = true;
            break;
            case 2:
                if(!stampaAutoCil_1500(autoMobili, numAuto)){
                    cout << "Non ci sono possessori con auto di cilindrata > 1500\n";
                } 
            break;
            case 3:
                cout << "Il numero auto immatricolate nel " << getNumAutoAnnoMin(autoMobili, numAuto) << endl;
            break;

            case 4:
                ordina(autoMobili, numAuto);
                stampaAuto(autoMobili, numAuto);
            break;

            case 5:
                stampaAutoPerAnno(autoMobili, numAuto);
            break;
                
            break;

            case 0: break;
        }
        pause();
        cls();
    }while(s!=0);


}