package negozio;

public class Prodotto {
	
	int codProdotto;
	String nome;
	double prezzo;

    public Prodotto(int codice, String _nome, double price){
        codProdotto = codice;
        nome = _nome;
        prezzo = price;
    }

    String stampa(){
        return "Codice: " +
                codProdotto +
                " Nome: " +
                nome +
                " Prezzo: "+prezzo;
    }

}
