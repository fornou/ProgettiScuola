#include <iostream>

using namespace std;

class Giocatore{
    private:
        int vita;
        string tipo;

    public:
    // Costruttore
    Giocatore(int vita) {
        this->vita = vita;
    }

    // Metodi di ottenimento
    string getVita() const {
        return vita;
    }

    // Metodi di modifica
    void setVita(string nuovaVita) {
        vita = nuovaVita;
    }

    void stampaInformazioni() const {
        cout << "Vita: " << getVita() << endl;
    }

    void estraiColpo(){
        int scelta;

        srand (time(NULL));
        scelta = rand() % 2 + 1;

        if(scelta){
            setColore("Rosso");
            setTipo("Dannoso");
            setDanno(1);
        }else{
            setColore("Nero");
            setTipo("Non dannoso");
            setDanno(0);
        } 
        
    }
};