#include "../libreries/libreria.h"

int scelta(vector<string>m, int s){
    menuDinamico(m);//mostra menu e mi fa fare la scelta
    cout << "Digita scelta: " << endl;
    s = in_int(s);
    return s;
}

double costo_prodotto(int s, double costo){
    switch (s)//funzione scelta che restituisce un valore intero
    {
        case 1:
            costo = 0.50;
        break;

        case 2:
            costo = 0.80;
        break;

        case 3:
            costo = 1;
        break;
    }
    return costo;
}

double ins_soldi(double moneta_ins){
    do{
        moneta_ins = in_double(moneta_ins);
    }while(!ctrl_monete_esistenti(moneta_ins));
    return moneta_ins;
}

double calc_soldi_rim(double rim, double si){
    return rim - si;
}

bool ctrl_soldi_rim(double s, string p){
    bool esci = false;
    if(s < 0){
        double resto = abs(s);
        cout << "Ecco a te " << p << " ed ecco il tuo resto di " << resto << " euro\n";
        esci = true;
    }else if(s == 0){
        cout << "Ecco a te " << p <<endl;
        esci = true;
    }else{
        cout << "Ti mancano ancora " << s << " euro da inserire\n";
    }
    return esci;
}

int main()
{
    cls();
    double costo_prod_sel, moneta_ins, soldi_rim, tot_ins;
    vector <string> menu = {"Acqua","Bibita in lattina","Bibita in bottiglietta", "Esci"};
    string risp, prod_sel;
    bool esci;
    int s = 0;
    
    do{
        s = scelta(menu, s);
        prod_sel = menu[s-1];
        tot_ins = 0;
        if(s != 4){
            costo_prod_sel = costo_prodotto(s, costo_prod_sel);//mi restituisce il costo del prodotto selezionato
            soldi_rim = costo_prod_sel;
            cls();
            do{
                cout << "\t\tPAGAMENTO\n";
                cout << "Costo " << prod_sel << ": " << costo_prod_sel << "euro\tCosto Inserito: " << tot_ins << "euro" << endl;
                cout << "Inserisci soldi per il prodotto selezionato: \n";
                moneta_ins = ins_soldi(moneta_ins);
                tot_ins += moneta_ins;
                cls();
                soldi_rim = calc_soldi_rim(soldi_rim, moneta_ins);
                esci = ctrl_soldi_rim(soldi_rim, prod_sel);
                pause();
                cls();
            }while(!esci);
        }
        cls();
        risp = in_risp("Vuoi uscire?",risp);
        cls();    
    }while(risp != "s");   
}




