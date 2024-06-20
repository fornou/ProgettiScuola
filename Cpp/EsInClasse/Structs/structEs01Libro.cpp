#include "../Libreries/libArray.h"
struct libro
{
    string titolo, autore, editore;
    int nPag;
    double prezzo;
};
#define DIM 50

void inserisci(int n, libro l1[]){
    for(int i = 0; i < n; i++){
        l1[i].titolo = in_parola_spazi("inserisci titolo libro", l1[i].titolo);
        l1[i].autore = in_parola_spazi("inserisci autore libro", l1[i].autore);
        l1[i].editore = in_parola_spazi("inserisci editore libro", l1[i].editore);

        l1[i].nPag = in_int("inserisci il numero delle pagine", l1[i].nPag);

        l1[i].prezzo = in_double("inserisci il prezzo", l1[i].prezzo);
    }
}

void stampa(int n, libro l1[]){
    cout << setw(40) << left << "Titolo"
              << setw(35) << "Autore"
              << setw(35) << "Editore"
              << setw (10) << "Pagine"
              << setw (10) << "Prezzo" << endl;

    // Stampare i dati dei libri
    for(int i = 0; i < n; i++) {
        cout << setw(40) << left << l1[i].titolo
                  << setw(35) << l1[i].autore
                  << setw(35) << l1[i].editore
                  << setw(10) << l1[i].nPag
                  << setw(10) << fixed << setprecision(2) << l1[i].prezzo << endl;
    }
    cout <<"_______________________________" << endl;
}

void scambia(libro &l1, libro &l2){
    libro l3 = l1;
    l1 = l2;
    l2 = l3;
}

void switchTipo(int criterio, libro &l1, libro &l2){
    if (criterio == 1) {
        if(l1.titolo>l2.titolo){
                scambia(l1, l2);
        }
    }else if (criterio == 2) {
        if(l1.autore>l2.autore){
            scambia(l1, l2);
        }        
    } else if (criterio == 3) {
        if(l1.editore>l2.editore){
            scambia(l1, l2);
        }
    } else if (criterio == 4) {
        if(l1.nPag>l2.nPag){
            scambia(l1, l2);
        }
    } else if (criterio == 5) {
        if(l1.prezzo>l2.prezzo){
            scambia(l1, l2);
        }
    }
}

void ordina(int n, libro l1[], int criterio){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            switchTipo(criterio, l1[i], l1[j]);
        }
    }
}

int main(){
    //libro l1[DIM];
    //int n = newDimArray(n, DIM, "libri");
    //inserisci(n, l1);
    string s = "";
    libro l1[6] = {
        { "z", "q", "effffffff", 10, 5 },
        { "n", "zfffff", "q", 1, 8 },
        { "afffff", "n", "z", 9, 2 },
        { "d", "a", "n", 2, 9 },
        { "efffffffff", "d", "a", 8, 1 },
        { "qfff", "efffffffff", "d", 5, 10 }
    };
    do{
        cls();
        stampa(6, l1);
        int v = in_int("Ordina per:\n1-titolo\n2-autore\n3-editore\n4-pagine\n5-prezzo\nScelta:",v);
        ordina(6, l1, v);
        stampa(6, l1);
        pause();
        cls();
        s = in_risp("uscire: ", s);
    }while(s == "n");
    
}