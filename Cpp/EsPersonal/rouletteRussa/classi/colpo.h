#include <iostream>

using namespace std;

class Colpo{
    private:
        string tipo;
        string colore;
        int danno;

    public:
    // Costruttore
    Colpo(string tipo, string colore, float danno) {
        this->tipo = tipo;
        this->colore = colore;
        this->danno = danno;
    }

    // Metodi di ottenimento
    string getTipo() const {
        return tipo;
    }
    string getColore() const {
        return colore;
    }
    float getDanno() const {
        return danno;
    }

    // Metodi di modifica
    void setTipo(string nuovoTipo) {
        tipo = nuovoTipo;
    }
    void setColore(string nuovoColore) {
        colore = nuovoColore;
    }
    void setDanno(int nuovoDanno) {
        danno = nuovoDanno;
    }

    void stampaInformazioni() const {
        cout << "Tipo: " << getTipo() << endl;
        cout << "Colore: " << getColore() << endl;
        cout << "Danno: hp" << getDanno() << endl;
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