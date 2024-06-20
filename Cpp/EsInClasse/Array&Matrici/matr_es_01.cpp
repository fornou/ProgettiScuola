#include "libArray.h"
#define giorno 100  // colonna
#define prodotto 20 // riga

void caricaMatrice(int tv[][giorno], int r, int c){
    srand(time(0));
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            tv[i][k] = rand_in_range(0, 10);
        }
    }
}

void caricaMatrice2(int tv[][giorno], int tv2[][giorno], int r, int c){
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            tv2[i][k] = tv[i][k];
        }
    }
}

void stampaMatrice(int tv[][giorno], int r, int c){
    cout << "\t  STAMPA DEI DATI\n";
    cout << "Prodotti: " << r << "\t|\tGiorni: " << c << "\n";
    for (int i = 0; i < r; i++)
    {
        cout << "prod_" << (i+1) << "   \t|\t";
        for (int k = 0; k < c; k++){
            cout << tv[i][k];
            cout << " ";
        }
        cout << "\n";
    }
}

double calcMediaProd(int tv[][giorno], int r, int c, double media){
    int n = ins_in_range(n, 1, r); // ins in range giorno e prodotto
    for (int i = 0; i < c; i++){
        media += tv[n-1][i];
    }
    return media /= c;
}

double calcMediaGiorno(int tv[][giorno], int r, int c, double media){
    int n = ins_in_range(n, 1, c); // ins in range giorno e prodotto
    for (int i = 0; i < r; i++){
        media += tv[i][n-1];
    }
    return media /= r;
}

void creaArrayVendite(int tv[][giorno], int r, int c, int v[]){
    int n = ins_in_range(n, 1, r);
    for (int i = 0; i < c; i++){
        v[i] = tv[n-1][i];
    }
}

bool cercaVendite(int tv[][giorno], int r, int c){
    bool trov = false;
    int ric = in_int(ric);
    cout << "Valore inserito trovato in:\n";
    for (int i = 0; i < r; i++){
        for (int k = 0; k < c; k++){
            if (tv[i][k] == ric){
                trov = true;
                cout <<"Rig." << (i+1) << " - Col." << (k+1) << "\n";
            }
        }
    }
    return trov;
}

void ordinaMatrice(int tv[][giorno], int r, int c){
    for (int i = 0; i < r; i++){
        bubbleSort(tv[i], c);
    }
}

int main(){
    setlocale(LC_ALL, "Italian");

    int tavola[prodotto][giorno];
    int tavola2[prodotto][giorno];
    int vendite[giorno];
    double med = 0;
    int giorn, prod, giorn2, prod2;
    
    cls();
    cout <<"\t  NUMERAZIONE GIORNI E PRODOTTI\n";
    prod = newDimArray(prod, prodotto, "prodotti");
    giorn = newDimArray(giorn, giorno, "giorni");
    cls();

    caricaMatrice(tavola, prod, giorn);

    stampaMatrice(tavola, prod, giorn);
    
    cout << "    MEDIA VENDITE DATO PRODOTTO\n";
    cout << "Inserisci numero prodotto: ";
    med = calcMediaProd(tavola, prod, giorn, 0);
    cout << "La media vendite del prodotto: " << med <<endl;
    pause();
    cls();

    med = 0;
    stampaMatrice(tavola, prod, giorn);
    cout << "    MEDIA VENDITE DATO GIORNO\n";
    cout << "Inserisci numero giorno: ";
    med = calcMediaGiorno(tavola, prod, giorn, 0);
    cout << "La media vendite del giorno: " <<  med << endl;
    pause();
    cls();

    stampaMatrice(tavola, prod, giorn);
    cout << "    POSIZIONE VENDITA RICERCATA\n";
    cout << "Inserisci numero vendite: ";
    if (!cercaVendite(tavola, prod, giorn)){
        cout << "Nessuna posizione trovata\n";
    }
    pause();
    cls();

    stampaMatrice(tavola, prod, giorn);
    cout << "    CREAZIONE ARRAY VENDITE\n";
    cout << "Inserisci numero prodotto: ";
    creaArrayVendite(tavola, prod, giorn, vendite);
    stampa2(vendite, giorn);
    pause();

    cout << "    ORDINAZIONE ARRAY VENDITE\n";
    bubbleSort(vendite, giorn);
    stampa2(vendite, giorn);
    pause();
    cls();

    cout <<"NUMERAZIONE GIORNI E PRODOTTI PER MATRICE 2\n";
    prod2 = newDimArray(prod, prod, "prodotti");
    giorn2 = newDimArray(giorn, giorn, "giorni");
    cls();

    cout << "     CONFRONTO TRA DUE MATRICI\n";
    caricaMatrice2(tavola, tavola2, prod2, giorn2);
    cout << "\t     ORIGINALE\n";
    stampaMatrice(tavola, prod, giorn);
    cout << "\t      COPIA\n";
    stampaMatrice(tavola2, prod2, giorn2);
    pause();
    cls();

    cout << "MATRICE 2 E MATRICE ORDINATA\n";
    stampaMatrice(tavola2, prod2, giorn2);
    ordinaMatrice(tavola2, prod2, giorn2);
    stampaMatrice(tavola2, prod2, giorn2);
    

    return 0;
}
