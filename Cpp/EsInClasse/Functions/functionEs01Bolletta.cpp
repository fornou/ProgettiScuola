#include "../libreries/libreria.h"// da cambiare in base alla posizione del file.h

bool input_data(string &n, double &v1, double &v2){
    bool v;
    cout << "Inserisci il nome dell'utente\n";
    n = in_parola(n);
    do{
        cout << "Inserisci il numero della lettura precedente\n";
        v1 = in_double(v1);
        cout << "Inserisci il numero della lettura attuale\n";
        v2 = in_double(v2);
        v = ctrl_first_min(v1, v2);
        if(!v){
            cls();
            cout << "Caro utente " << n <<", il secondo valore e' minore del primo\n";
        }
    }while(!v);
    return true;
}

double calc_consumo(double v1, double v2){
    return v2 - v1;
}

double calc_quota(int p, double t){
    return (t * p)/100;
}

double calc_imp_tot(double c){
    return c * 0.07;
}

double calc_costo_fin(double t, double q){
    return t + q;
}

int get_perc(double c){
    int p = 0;
    if(c < 250){
        p = 15;
    }else if(c >= 250 && c <= 500){
        p = 25;
    }
    else{
        p = 30;
    }
    return p;
}

void stampa_bolletta(string n, double kwh_prec, double kwh_att, bool ins){
    double consumo, importo_tot, quota, costo_fin;
    int perc;
    
    if(ins){
        consumo = calc_consumo(kwh_prec, kwh_att);
        importo_tot = calc_imp_tot(consumo);
        perc = get_perc(consumo);
        quota = calc_quota(perc, importo_tot);
        costo_fin = calc_costo_fin(importo_tot, quota);

        cout << "Bolletta di "<< n 
             << "\nConsumo\tImporto Tot\tPercentuale\tQuota\tCosto Finale\n"
             << consumo << "\t" << importo_tot << "\t\t" << perc << "\t\t" << quota << "\t" << costo_fin << endl;
    }else{
        cout << "Error!! Devi prima inserire\n";
    }
}

int scelta(int s){
    cout << "_______________________\n\n";                       
    cout << "         MENU'         \n";
    cout << "_______________________\n\n";
    cout << "1. Inserimento Dati\n";
    cout << "2. Stampa Bolletta Luce\n";
    cout << "3. Esci\n";
    cout << "Digita scelta: " << endl;
    s = in_int(s);
    return s;
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string nome = "";
    bool inserito = false;
    double kwh_prec, kwh_att;
    int s;
    
    do{
        s = scelta(s);
        cls();

        switch(s){
            case 1:
                inserito = input_data(nome, kwh_prec, kwh_att);
            break;
            case 2:
                stampa_bolletta(nome, kwh_prec, kwh_att, inserito);
                pause();
            break;
            case 3:
            break;
        }
        cls();    
    }while(s != 3); 
      
}
