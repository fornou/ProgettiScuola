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




// string getPizzaByPos(int pos, pizza p[]){
//     basic_stringstream ss;
//     ss.str("");
//     ss.clear();
//     ss << p[pos].nome << " " << p[pos].prezzo;
//     return ss.str();
// }

string getNomePizzaByPos(int pos, pizza p[]){
    return p[pos].nome;
}

double getPrezzo(int pos, pizza p[]){
    return p[pos].prezzo;
}

bool ricPizzeCostoMin(int n, pizza p[]){
    bool trov = false;
    int ric = in_double("Costo da ricercare:", ric);
    cls();
    cout << "Pizze con costo minore di " << ric << ":"<< endl;
    for (int i = 0; i < n; i++){
        if (p[i].prezzo < ric){
            cout << p[i].nome << " " << p[i].prezzo<< endl;
            //cout << getPizzaByPos(i, p) << endl;
            trov = true;
        }   
    }
    return trov;
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

double costoMag(int n, pizza p[]){
    double max = 0;
    for (int i = 0; i < n; i++){
        if(getPrezzo(i, p)>max){
            max = getPrezzo(i, p);
        }
    }
    return max;
}

void ricPizzaByCosto(int n, pizza p[]){
    for (int i = 0; i < n; i++){
        if(getPrezzo(i, p) == costoMag(n, p)){
            cout << p[i].nome << " " << p[i].prezzo<< endl;
            //cout << getPizzaByPos(i, p) <<endl;
        }
    }
}

double mediaCosto(int n, pizza p[]){
    double somma;
    for (int i = 0; i < n; i++){
        somma += getPrezzo(i, p);
    }
    return somma/=n;
}





void scambia(pizza &p1, pizza &p2){
    pizza p3 = p1;
    p1 = p2;
    p2 = p3;
}

void ordina(int n, pizza p[]){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            if(p[i].nome>p[j].nome){
                scambia(p[i], p[j]);
            }
        }
    }
}






void caricaOrdine(pizza p[], ordine &o, int numPizze, int numPizzeOrd){
    bool gira;
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
                o.costoCoperto = in_double("Inserisci costo coperto", o.costoCoperto) ;
                o.costoBevanda = in_double("Inserisci costo coperto", o.costoBevanda) ;
                o.mancia = in_double("Inserisci mancia", o.mancia);
            }
        }while(!gira);
    }
}

void stampaOrdine(pizza p[], ordine &o, int numPizzeOrd){
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

double conto(pizza p[], ordine &o, int numPizzeOrd){
    double contoTot;
    for (int i = 0; i < numPizzeOrd; i++){ 
        contoTot += double(o.p[i].prezzo * o.quantita[i]);
    }
    contoTot += o.costoBevanda + o.costoCoperto + o.mancia;
    return contoTot;
}





void stampaMenu(){
     cout << "________________________________\n\n"                     
        <<   "              MENU'         \n"
        <<   "  ________________________________\n\n"
        <<   "   1) Inserimento Pizza\n"
        <<   "   2) Stampa Menu'\n"
        <<   "   3) Pizze che costano meno di X \n"
        <<   "   4) Prezzo medio delle pizze\n"
        <<   "   5) Ricerca pizza tramite nome\n"
        <<   "   6) Pizza piu' costosa\n"
        <<   "   7) Ordine alfabetico pizze\n"
        <<   "   8) Crea scontrino\n"
        <<   "   0) EXIT\n"
        <<   "  ________________________________\n";
        
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
    int s, n, numPizze, numPizzeOrd;
    bool t = false;
    
    do{
        cls();
        stampaMenu();
        if(!t){
            s = ins_in_range(s, 0, 1);
        }else{
             s = ins_in_range(s, 0, 8);
        }
        cls();
        switch (s){
            case 1:
                numPizze = newDimArray(numPizze, nPiz, "pizze");
                cls();
                caricaPizze(numPizze, pizze);
                t = true;
            break;
            case 2:
                cout << "Menu'\n";
                stampaPizze(numPizze, pizze);
            break;
            case 3:
                if(!ricPizzeCostoMin(numPizze, pizze)){
                    cout << "Non ci sono pizze con costo minore di quello inserito\n";
                }
            break;

            case 4:
                cout << "Costo medio delle pizze del menu': " << mediaCosto(numPizze, pizze);
            break;

            case 5:
                if(!ricPizzaByNome(numPizze, pizze)){
                    cout << "Non ci sono pizze con questo nome\n";
                }
            break;

            case 6:
                cout << "Pizza/e del menu con costo maggiore': " << endl;
                ricPizzaByCosto(numPizze, pizze);
            break;

            case 7:
                cout << "Pizze in ordine alfabetico"<<endl;
                ordina(numPizze, pizze);
                stampaPizze(numPizze, pizze);
            break;

            case 8:
                numPizzeOrd = newDimArray(numPizzeOrd, numPizze, "tipi pizze per ordine");
                caricaOrdine(pizze, ord1, numPizze, numPizzeOrd);
                cls();
                stampaOrdine(pizze,ord1,numPizzeOrd);
                cout << "Il conto totale e': " << conto(pizze, ord1, numPizzeOrd);
            break;

            case 0: break;
                
            default:
                cout << "Non compreso\n";
            break;
        }
        cout << endl;
        pause();
        cls();
    }while(s!=0);


    return 0;
}
