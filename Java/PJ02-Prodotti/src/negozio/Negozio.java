package negozio;
import utili.Utl;

public class Negozio {
    public static void main(String[] args) {
        Utl.cls();

        Scontrino s = new Scontrino();
        Prodotto p = new Prodotto(1, "Giacca", 19.99);
        Prodotto p1 = new Prodotto(2, "Felpa", 10.99);

        s.addProdotto(0, p);
        s.addProdotto(1, p1);

        Utl.prntString(s.stampa());

        Utl.pause();
        Utl.cls();
    }
}
