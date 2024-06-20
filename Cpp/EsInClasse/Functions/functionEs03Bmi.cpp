#include "../libreries/libreria.h"

bool convertiPeso(double &p){
    p = p * 0.453592;
    return true;
}

bool convertiAltezza(double &h){
    h = h * 0.3048;
    return true;
}

double controlloKg(double &n, int s){
    do{
        cin >> n;
        if(s == 2)
        {
            convertiPeso(n);
        }
        if(n < 10 || n >180){
            cout << "Errore, ridigita peso: ";
        }
    }while(n<10 || n > 180);
    
    return n;
}

double controlloM(double &n, int s){
    do{
        cin >> n;
        if(s == 2)
        {
            convertiAltezza(n);
        }
        if(n < 0 || n > 2.2){
            cout << "Errore, ridigita altezza: ";
        }
    }while(n < 0 || n > 2.2);
    
    return n;
}

double calcolaBmi(double p, double h){
    double bim = 0;
    bim = p / (h*h);
    return bim;
}

bool insert(double &p, double &h, int s){
    cout << "Inserisci peso: ";
    p = controlloKg(p, s);
    cout << "Inserisci altezza: "; 
    h = controlloM(h, s);
    return true;
}

string dammiCategoria(double bmi){
    if(bmi < 16.5){
        return "Sottopeso severo";
    }else if(bmi >= 16.5 && bmi <= 18.4){
        return "Sottopeso";
    }else if(bmi >= 18.5 && bmi <= 24.9){
        return "Normale";
    }else if(bmi >= 25 && bmi <= 30){
        return "Sovrappeso";
    }else if(bmi >= 30.1 && bmi <= 34.9){
        return "Obesita' primo grado";
    }else if(bmi >= 35 && bmi <= 40){
        return "Obesita' secondo grado";
    }else{
        return "Obesita' terzo grado";
    }
}

int menu(){
    int s = 0;
    do{
        cout << "Menu'\n"
                "1. Inserimento dati (Misure italiane)\n"
                "2. Inserimento dati (Misure inglesi)\n"
                "3. Uscita\n";
        cin >> s;
        if(s > 3 || s < 1){
            s = 0;
            cout << "La scelta puo' essere solo 1, 2 o 3";
        }
    }while(s > 3 || s < 1);

    return s;
}

int main(){

    int scelta = 0;
    double peso, altezza, bmi;
    string categoria;
    bool inserito = false;

    do{
        system("cls");
        inserito = false;
        scelta = menu();

        switch (scelta)
        {
            case 1:
                system("cls");
                cout << "Inserimento dati (Misure italiane)\n";
                inserito = insert(peso, altezza, scelta);              
            break;
            
            case 2:
                system("cls");
                cout << "Inserimento dati (Misure inglesi)\n";   
                inserito = insert(peso, altezza, scelta);
            break;

            case 3:
                
            break;
        }
        if(inserito){
            bmi = calcolaBmi(peso, altezza);
            categoria = dammiCategoria(bmi);
            cout << "Insermimento avvenuto con successo!" << endl;
            cout << "Bmi = " << bmi << endl;
            cout << "Categoria = " << categoria << endl;
            system("pause"); 
        }

    }while(scelta!=3);

}