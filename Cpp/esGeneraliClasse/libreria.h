#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <istream>
#include <windows.h>
#include <cstdlib>
#include <thread> 
#include <chrono>
#include <locale>
#include <conio.h>
#include <vector>
#include <algorithm> 
#include <math.h>
#include <string.h>
#include <cmath>
#include <ctype.h>
#include <limits> 
#include <iomanip> // Per setw
#include <string>

using namespace std;
using namespace this_thread;
using namespace chrono;

//DI SISTEMA

void cls(){
    system("cls");
}

void pause(){
    cout << "INVIO...";
    cin.get();
}


//CONTROLLI

bool ctrl_par(string s){
    bool c = true;
    string alfabeto = "abcdefghijklmnopqrstuvxywz ";
    string alfabetoMaiusc = "ABCDEFGHIJKLMNOPQRSTUVXWYZ ";
    char lettPar, lettParMaiusc, lettAlf, lettAlfMaiusc;

    for(int i = 0; i < s.length(); i++)
    {
        lettPar = s[i];
        lettParMaiusc = toupper(s[i]);
        size_t found = alfabeto.find(lettPar);
        size_t foundM = alfabetoMaiusc.find(lettParMaiusc);
        if(found == string::npos && foundM == string::npos){// se sono uguali è perchè non è stato trovato
            c = false;
            break;
        }
    }
    return c;
}

bool ctrl_num(){
    bool r = true;
    if(cin.fail()){// caso di input errato completamente tipo inserire una lettera
        cout << "Error!! Inserimento completamente errato\n";
        cin.clear();// resetta lo stato della funzione che restituisce 1 o 0 del cin in errore
        cin.ignore(1000, '\n'); // cancella i caratteri inseriti, resetta stato tastiera
        r = false;
    }else{
        cin.ignore(1000, '\n');
        if(cin.gcount()>1){ // numero + lettera
            cout << "Error!! Inserimento parzialemte errato\n";
            r = false;
        }
    }
    return r;
}

string ctrl_risp(string risp){
    do{
        cin >> risp;
        if(risp != "s" && risp != "n"){
            cout << "\nErrore, risposta non puo' essere diverso da s o n\n";
            cout << "Inserisci s o n: ";
        } 
    }while(risp != "s" && risp != "n");

    return risp;
}

bool ctrl_monete_esistenti(double s){
    bool v;
    vector<double> monete = {0.05, 0.02, 0.01, 0.10, 0.20, 0.50, 1, 2};
    if(find(monete.begin(), monete.end(), s) == monete.end()){
        v = false;
        cout << "Monete accettate: 0.01, 0.02, 0.05, 0.10, 0.20, 0.50, 1, 2\n";
    }else{
        v = true;
    }
    return v;
}

bool ctrl_first_min(double first, double second){
    if(first > second){
        return false;
    }else{
        return true;
    }
}

bool ctrl_first_mag(double first, double second){
    if(first < second){
        return false;
    }else{
        return true;
    }
}


//INSERIMENTO NORMALE
string in_parola(string s){
    do{
        cin >> s;
        if(!ctrl_par(s)){
            cout << "Errore e' presente un numero\n";
        }
    }while(!ctrl_par(s));   
    return s;
}

string in_parola_spazi(string s){
    do{
        getline(cin, s);
        if(!ctrl_par(s)){
            cout << "Errore e' presente un numero\n";
        }
    }while(!ctrl_par(s));   
    return s;
}

string in_string(string s){
    cin >> s;
    return s;
}

string in_string_spazi(string s){
    getline(cin, s);
    return s;
}

double in_double(double n){
    do{
        cin >> n;
    }while(!ctrl_num());
    return n;
}

int in_int(int n){
    bool v;
    do{
        cin >> n;
        v = ctrl_num();
        if(!v){cout << "Inserisci numero intero"<<endl;}
    }while(!v);
    return n;
}

double ins_in_range(double n, double min, double max){
    bool v = false;
    do{
        n = in_double(n);
        if(n <= max && n >= min){
            v = true;
        }else{
            cout << "Errore, numero non compreso\n";
            cout << "Arco di valori accettati: " << min << "-" << max << endl;
            v = false;
        }
    }while(!v);
    return n;
}



//INSERIMENTO CON TEXT INTEGRATO
double in_double(string text, double d){
    cout << text << endl;
    d = in_double(d);
    return d;
}

int in_int(string text, int i){
    cout << text << endl;
    i = in_int(i);
    return i;
}

double ins_in_range(string text, double n, double min, double max){
    cout << text << endl;
    n = ins_in_range(n, min, max);
    return n;
}

string in_parola(string text, string r){
    cout << text << endl;
    r = in_parola(r);
    return r;
}

string in_string(string text, string r){
    cout << text << endl;
    r = in_string(r);
    return r;
}

string in_parola_spazi(string text, string r){
    cout << text << endl;
    r = in_parola_spazi(r);
    return r;
}

string in_string_spazi(string text, string r){
    cout << text << endl;
    r = in_string_spazi(r);
    return r;
}

string in_risp(string text, string r){
    cout << text << endl;
    r = ctrl_risp(r);
    return r;
}

//MENU DINAMICO

void menuDinamico(vector<string> g1){
    //si richiama così menuDinamico(sceltePossibili);
    //prende un vettore come parametro e ne crea un menù visivo
    //vector<string> sceltePossibili = {"A","B","C","D","E","F","G","H"};
    //vector<string> sceltePossibili = {"ruvido","liscio","bagnato","ghicciato","Esci"};
    //richiamo in main -> menuDinamico(sceltePossibili);
    cout << "_______________________\n\n";                       
    cout << "         MENU'         \n";
    cout << "_______________________\n\n";
    cout << "Effettua la tua scelta:\n";
    int cont = 1;

    for (auto i = g1.begin(); i != g1.end(); i++)
    {
        cout <<"-" <<cont << " " << *i << "\n";
        cont++;
    }  

}


//GENERAZIONE RANDOM

int rand_in_range( int min, int max){
    int d = max - min +1, n;
    n = rand() % d + min;
    return n;
}


