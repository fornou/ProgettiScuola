package model;

public class Film {
	private int id, anno;
	private String titolo, regista;
	private double rating;
	
	//Getters & Setters
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getAnno() {
		return anno;
	}
	public void setAnno(int anno) {
		this.anno = anno;
	}
	public String getTitolo() {
		return titolo;
	}
	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}
	public double getRating() {
		return rating;
	}
	public void setRating(double rating) {
		this.rating = rating;
	}
	public String getRegista() {
		return regista;
	}
	public void setRegista(String regista) {
		this.regista = regista;
	}
	
	//ToString
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Film [id=");
		builder.append(id);
		builder.append(", anno=");
		builder.append(anno);
		builder.append(", titolo=");
		builder.append(titolo);
		builder.append(", rating=");
		builder.append(rating);
		builder.append(", regista=");
		builder.append(regista);
		builder.append("]");
		return builder.toString();
	}
	
	
	
	
	
	
	
	
}
