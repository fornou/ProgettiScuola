#include "libArray.h"
#define nPiz 50
#define nIn 50
struct pizza{
    int numIn;
    string nome, ingredienti[nIn];
    double prezzo;
};
struct ordine{
    pizza p[nPiz];
    int quantita[nPiz];
    double costoBevanda, costoCoperto, mancia;
};



void inserisciPizza(pizza p[], int i){
    cout << "Inserimento Pizza:\n";
    p[i].nome = in_parola_spazi("inserisci nome pizza", p[i].nome);
    p[i].prezzo = in_double("inserisci prezzo", p[i].prezzo);
    p[i].numIn = newDimArray(p[i].numIn, nIn, "ingredienti");
    for (int j = 0; j < p[i].numIn; j++){
        p[i].ingredienti[j] = in_parola_spazi("inserisci nome ingrediente", p[i].ingredienti[j]);
    }
    cls();
}

void caricaPizze(int n, pizza p[]){
    for (int i = 0; i < n; i++){
        inserisciPizza(p, i);
    }
}

int dimMaxCampo(int posIn, pizza p[]){
    int max = 0, dim;
    for (int j = 0; j < p[posIn].numIn; j++){
        dim = p[j].ingredienti[posIn].length();
        if (dim > max){max = dim;}
    }
    return max;
}

int sommaMax(int numPizze, pizza p[]){
    int somma = 0;
    for (int i = 0; i < numPizze; i++){
        somma += dimMaxCampo(i, p);
    }
    somma += (numPizze * 2);
    return somma;
}

int numMaxIng(int n, pizza p[]){
    int max = 0;
    for (int i = 0; i < n; i++){
        if (p[i].numIn > max){
            max = p[i].numIn;
        }
    }
    return max;
}

void stampaPizze(int n, pizza p[])
{
    int max;
    cout << setw(25) << left << "Nome"
         << setw(10) << "Prezzo"
         << setw(sommaMax(numMaxIng(n, p), p)) << "Ingredienti " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(25) << left << p[i].nome
             << setw(10) << left << p[i].prezzo;
        for (int j = 0; j < p[i].numIn; j++)
        {
            max = dimMaxCampo(j, p);
            cout << setw(max + 2) << left << p[i].ingredienti[j];
        }
        cout << endl;
    }
}




string getPizzaByPos(int pos, pizza p[]){
    stringstream ss;
    ss.str("");
    ss.clear();
    ss << p[pos].nome << " " << p[pos].prezzo;
    return ss.str();
}

string getNomePizzaByPos(int pos, pizza p[]){
    return p[pos].nome;
}

double getPrezzo(int pos, pizza p[]){
    return p[pos].prezzo;
}

bool ricPizzaByNome(int n, pizza p[]){
    bool trov = false;
    string ric = "";
    ric = in_parola_spazi("Pizza da ricercare:", ric);
    cls();
    cout << "Pizza con nome " << ric << ":"<< endl;
    for (int i = 0; i < n; i++){
        if (p[i].nome == ric){
            cout << p[i].nome << " " << p[i].prezzo<< endl;
            //cout << getPizzaByPos(i, p) <<endl;
            trov = true;
        }   
    }
    return trov;
}



void caricaOrdine(pizza p[], ordine o, int numPizze, int numPizzeOrd){
    bool gira, ok = false;
    for(int i = 0; i < numPizzeOrd; i++){
        stampaPizze(numPizze, p);
        cout << "Inserimento pizze per pagamento:\n";
        do{ 
            gira = ricPizzaByNome(numPizze,p);
            if(!gira){
                cout << "Non ci sono pizze con questo nome\n";
            }else{
                o.p[i].nome = getNomePizzaByPos(i, p);
                o.quantita[i] = in_int("Inserisci quantita:", o.quantita[i]);
                ok = true;
            }
        }while(!gira);
    }
    if(ok){
        o.costoCoperto = in_double("Inserisci costo coperti", o.costoCoperto) ;
        o.costoBevanda = in_double("Inserisci costo bevande", o.costoBevanda) ;
        o.mancia = in_double("Inserisci mancia", o.mancia);
    }
   
}

void stampaOrdine(ordine o, int numPizzeOrd){
    cout << setw(25) << left << "Nome"
         << setw(10) << "Prezzo"
         << setw(10) << "Quantita" <<endl;
         
    for (int i = 0; i < numPizzeOrd; i++){
        cout <<setw(25) << left << o.p[i].nome 
            << setw(10) << left << o.p[i].prezzo 
            << setw(10)<< left << o.quantita[i] << endl;
    }
    cout <<  "Costo Bevanda"<< o.costoBevanda 
         <<  "\nCosto Coperto"<< o.costoCoperto
         <<  "\nMancia" << o.mancia << endl;
}

double conto(ordine o, int numPizzeOrd){
    double contoTot = 0;
    for (int i = 0; i < numPizzeOrd; i++){ 
        contoTot += double(o.p[i].prezzo * o.quantita[i]);
    }
    contoTot += o.costoBevanda + o.costoCoperto + o.mancia;
    return contoTot;
}

int main(int argc, char const *argv[])
{
    cls();

    // Definizione delle pizze con i loro ingredienti e prezzi
    // pizza pizze[] = {
    //     {3, "Margherita", {"Pomodoro", "Mozzarella", "Basilico"}, 7.50},
    //     {4, "Capricciosa", {"Pomodoro", "Mozzarella", "Prosciutto Cotto", "Funghi"}, 9.00},
    //     {5, "Quattro Stagioni", {"Pomodoro", "Mozzarella", "Prosciutto Cotto", "Funghi", "Carciofi"}, 10.50},
    //     {4, "Diavola", {"Pomodoro", "Mozzarella", "Salsiccia Piccante", "Peperoncino"}, 8.50},
    //     {3, "Vegetariana", {"Pomodoro", "Mozzarella", "Verdure Grigliate"}, 8.00}};
    pizza pizze[nPiz];
    ordine ord1;
    int numPizze, numPizzeOrd;
    
   
    numPizze = newDimArray(numPizze, nPiz, "pizze");
    cls();
    caricaPizze(numPizze, pizze);
    stampaPizze(numPizze, pizze);
    pause();
    
    numPizzeOrd = newDimArray(numPizzeOrd, numPizze, "tipi pizze per ordine");
    caricaOrdine(pizze, ord1, numPizze, numPizzeOrd);
    pause();
    cls();
    stampaOrdine(ord1,numPizzeOrd);
    cout << "Il conto totale e': " << conto(ord1, numPizzeOrd);
            
    pause();
    cls();


    return 0;
}
