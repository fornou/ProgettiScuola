package negozio;

public class Scontrino {
    String descrizione;
    Prodotto[] prodotti;
    double totale;

    Scontrino(){
        totale = 0;
        prodotti = new Prodotto[2];
        descrizione = "Negozio Abbigliamento";
    }

    void addProdotto(int posizione, Prodotto p){
        prodotti[posizione] = p;
    }

    String stampa(){
        String contenuto = "";
        contenuto += descrizione;
        contenuto += "\n";

        contenuto += "Elenco prodotti";
        contenuto += "\n";

        for(int i = 0; i < prodotti.length; i ++){
            Prodotto temp = prodotti[i];
            totale += temp.prezzo;
            //totale += prodotti[i].prezzo;

            contenuto += prodotti[i].stampa();
            contenuto += "\n";
        }

        contenuto += "Totale scontrino " + totale + "€";

        return contenuto;
    }
} 
