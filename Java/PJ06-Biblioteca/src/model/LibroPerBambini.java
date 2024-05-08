package model;

public class LibroPerBambini extends Libro{
	private int etaConsigliata;
	
	public LibroPerBambini() {
		super();
	}

	public int getEtaConsigliata() {
		return etaConsigliata;
	}

	public void setEtaConsigliata(int etaConsigliata) {
		this.etaConsigliata = etaConsigliata;
	}
	
	public String getDescrizione() {
		return super.getDescrizione() + "Età consigliata: " + this.etaConsigliata;
	}
	
	
	
	
}
