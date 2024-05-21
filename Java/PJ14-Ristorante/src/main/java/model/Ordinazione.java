package model;

public class Ordinazione {
	
	private int id;
	private Piatto primo, secondo, dessert, bevande;
	private double prezzo;
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public Piatto getPrimo() {
		return primo;
	}
	public void setPrimo(Piatto primo) {
		this.primo = primo;
	}
	public Piatto getSecondo() {
		return secondo;
	}
	public void setSecondo(Piatto secondo) {
		this.secondo = secondo;
	}
	public Piatto getDessert() {
		return dessert;
	}
	public void setDessert(Piatto dessert) {
		this.dessert = dessert;
	}
	public Piatto getBevande() {
		return bevande;
	}
	public void setBevande(Piatto bevande) {
		this.bevande = bevande;
	}
	public double getPrezzo() {
		return prezzo;
	}
	public void setPrezzo(double prezzo) {
		this.prezzo = prezzo;
	}
	
	
	
	
}
