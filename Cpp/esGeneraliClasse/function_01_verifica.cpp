#include <iostream>
using namespace std;

bool contrNumerico(){
    system("cls");
    bool r = true;
    if(cin.fail()){
        cout << "Error!! inserimento completamente errato\n";
        cin.clear();
        cin.ignore(1000, '\n'); 
        r = false;
    }else{
        cin.ignore(1000, '\n');
        if(cin.gcount()>1){ // numero + lettera
            cout << "Error!! inserimento parzialemte errato\n";
            r = false;
        }
    }
    return r;
}

double controlPositive(){
    double n = 0;
    do{
        do{
            cin >> n;
        }while(contrNumerico);
        
        if(n <= 0)
            cout << "Errore, valore non puo' essere negativo o 0\n";
        
	}while(n<0);

    return n;
}

string controlRisp(){
    string risp = "";
    do{
        cin >> risp;
        if(risp != "s" && risp != "n"){
            cout << "\nErrore, risposta non puo' essere diverso da s o n\n";
            cout << "Inserisci s o n: ";
        } 
    }while(risp != "s" && risp != "n");

    return risp;
}

bool insertRisp(string &r){
    cout << "Inserisci s o n: ";
    r = controlRisp();

    return true;
}

bool insertValore(double &v){
    cout << "Inserisci il valore: ";
    v = controlPositive();
    return true;
}

bool controlNegativo(double s, double v){
    s -= v;
    if(s < 0){
        return true;
    }else{
        return false;
    }
}

double calcolaSaldo(double &s, double v, int sc){
    if(sc == 2){
         s -= v;
    }else if(sc == 3){
        s += v;
    }
    return s;
}

int menu(){
    int s = 0;
    do{
        do{
            cout << "**********************************************\n"
                "*               Conto corrente               *\n"
                "**********************************************\n"
                "*          Menu di scelta iniziale           *\n"
                "**********************************************\n"
                "*                 1. Saldo                   *\n"
                "*                2. Prelievo                 *\n"
                "*               3. Versamento                *\n"
                "*         4. Stampa Ultimo Movimento         *\n"
                "*                  5. Uscita                 *\n"
                "**********************************************\n"
                "Inserire la scelta (1, 2, 3, 4 oppure 5): ";
            cin >> s;
        }while(contrNumerico);
         
        if(s < 0 || s > 5){
            system("cls");
            cout << "Scelta non compresa nelle opzioni";
        }
    }while(s < 0 || s > 5);

    return s;
}

int main(){
    int scelta = 0;
    double saldo = 0, valore = 0;
    string risp = "";
    bool insPrelievo = false, insVersamento = false, insRisp = false, isNegativo = false;
    do{
        system("cls");
        isNegativo = false;
        scelta = menu();
        switch (scelta)
        {
            case 1:
                system("cls");
                cout << "Saldo disponibile: " << saldo << endl;
            break;
            case 2:
                system("cls");
                cout << "Operazione prelievo\n\n";
                cout << "Inserisci valore da prelevare saldo disponibile: " << saldo << endl;
                insPrelievo = insertValore(valore);
                isNegativo = controlNegativo(saldo, valore);
                if(insPrelievo){
                    if(isNegativo){
                        cout << "\nIl prelievo che stai effetuando e' maggiore"
                                "al saldo;\nLo sconfinamento del saldo richiede"
                                "interessi del 20%\nSei sicuro di voler svolgere"
                                "l'operazione? s = si n = no\n";
                        insRisp = insertRisp(risp);
                        if(insRisp){
                            if(risp == "s"){
                                saldo = calcolaSaldo(saldo, valore, scelta);
                                cout << "\nPrelievo effettuato!! Nuovo saldo aggiornato: " << saldo << endl;
                                insVersamento = false;
                            }
                            else{
                                cout << "Operazione annullata dall'utente!! saldo invariato: " << saldo << endl;
                                insPrelievo = false;
 
                            }
                        }
                    }
                    else{
                        saldo = calcolaSaldo(saldo, valore, scelta);
                        cout << "Prelievo effettuato!! Nuovo saldo aggiornato: " << saldo << endl; 
                        insVersamento = false;
                    }
                }

            break;
            case 3:
                system("cls");
                cout << "Operazione versamento\n\n";
                cout << "Inserisci valore da versare saldo disponibile: " << saldo << endl;
                insVersamento = insertValore(valore);
                if(insVersamento){
                    insPrelievo = false;
                    saldo = calcolaSaldo(saldo, valore, scelta);
                    cout << "\nVersamento effettuato!! Nuovo saldo aggiornato: " << saldo << endl; 
                }
            break;
            case 4:
                system("cls");
                cout << "Stampa ultimo movimento\n\n";
                if(insPrelievo){
                    cout << "Prelievo valore = " << valore << endl;
                }else if(insVersamento){
                    cout << "Versamento valore = " << valore << endl;
                }else{
                    cout << "Non hai ancora effettuato movimenti!!\n";
                }
            break;
            case 5:
                system("cls");
                cout << "Grazie per aver utilizzato il programma...\n";
            break;
        }
        cout << endl;
        system("pause");

    }while(scelta != 5);
    system("cls"); 
}
