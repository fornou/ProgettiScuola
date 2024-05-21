package model;

public class Libro implements Comparable<Libro>{
	
	private String titolo;
	private int pagine;
	private double prezzo;
	
	public String getTitolo() {
		return titolo;
	}
	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}
	public int getPagine() {
		return pagine;
	}
	public void setPagine(int pagine) {
		this.pagine = pagine;
	}
	public double getPrezzo() {
		return prezzo;
	}
	public void setPrezzo(double prezzo) {
		this.prezzo = prezzo;
	}
	@Override
	public int compareTo(Libro o) {
		//return this.titolo.compareTo(o.titolo);
		return Double.compare(this.prezzo, o.prezzo);
		//return this.pagine - o.pagine; 
	}
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Libro [titolo=");
		builder.append(titolo);
		builder.append(", pagine=");
		builder.append(pagine);
		builder.append(", prezzo=");
		builder.append(prezzo);
		builder.append("]");
		return builder.toString();
	}
	
}
