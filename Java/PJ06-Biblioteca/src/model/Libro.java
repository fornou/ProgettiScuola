package model;

public class Libro {
	
	private String titolo, autore;
	private boolean inPrestito; 
	
	public Libro() {
		this.inPrestito = false;
	}
	
	public Libro(String titolo) {
		this();//richiamo il primo costruttore
		this.titolo = titolo;
	}
	
	public Libro(String titolo, String autore) {
		this(titolo);
		this.autore = autore;
	}

	public String getDescrizione() {
		return "Titolo: " + this.titolo + " Autore: " + this.autore;
	}
	
	public String getTitolo() {
		return titolo;
	}

	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}

	public String getAutore() {
		return autore;
	}

	public void setAutore(String autore) {
		this.autore = autore;
	}

	public boolean isInPrestito() {
		return inPrestito;
	}

	public void setInPrestito(boolean inPrestito) {
		this.inPrestito = inPrestito;
	}
}
