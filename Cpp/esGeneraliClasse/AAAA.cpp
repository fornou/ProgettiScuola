#include <iostream>
#include <iomanip> // Per setw
#include <string>

struct Libro {
    std::string titolo;
    std::string autore;
    std::string editore;
    int nPag;
    double prezzo;
};

// Funzione per centrare il testo all'interno del campo
std::string centrato(const std::string& testo, int larghezza) {
    int spaziVuoti = larghezza - testo.length();
    if (spaziVuoti <= 0)
        return testo;

    int spaziPrima = spaziVuoti / 2;
    int spaziDopo = spaziVuoti - spaziPrima;
    
    return std::string(spaziPrima, ' ') + testo + std::string(spaziDopo, ' ');
}

void stampa(int n, Libro l1[]) {
    // Imposta la larghezza dei campi e allinea il testo a sinistra
    std::cout << std::setw(40) << std::left << "Titolo"
              << std::setw(35) << "Autore"
              << std::setw(35) << "Editore"
              << std::setw (5) << "Pagine"
              << std::setw (6) << "Prezzo" << std::endl;

    // Stampare i dati dei libri
    for(int i = 0; i < n; i++) {
        std::cout << std::setw(50) << std::left << l1[i].titolo
                  << std::setw(40) << l1[i].autore
                  << std::setw(40) << l1[i].editore
                  << std::setw(5) << l1[i].nPag
                  << std::setw(6) << std::fixed << std::setprecision(2) << l1[i].prezzo << std::endl;
    }
}



int main() {
    Libro libri[2] = {{"", "Autore1", "Ed1", 200, 19.99666},
                      {"Libro2", "Autore2", "Editore22222222", 300, 29.99666}};
    
    stampa(2, libri);

    return 0;
}
