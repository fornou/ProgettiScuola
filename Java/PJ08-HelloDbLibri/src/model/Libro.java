package model;

public class Libro {
	//Attributi Classe
	private String titolo, autore, editore, classificazione;
	private int id, anno; 
	
	
	//Costruttore di tutti i campi

	public Libro() {
	}
	public Libro(int id,String titolo, String autore, String editore, String classificazione, int anno) {
		this.id = id;
		this.titolo = titolo;
		this.autore = autore;
		this.editore = editore;
		this.classificazione = classificazione;
		this.anno = anno;
	}

	//Setters & Getters
	//Id
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	
	//Titolo
	public String getTitolo() {
		return titolo;
	}
	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}
	
	//Autore
	public String getAutore() {
		return autore;
	}
	public void setAutore(String autore) {
		this.autore = autore;
	}
	
	//Editore
	public String getEditore() {
		return editore;
	}
	public void setEditore(String editore) {
		this.editore = editore;
	}
	
	//Classificazione
	public String getClassificazione() {
		return classificazione;
	}
	public void setClassificazione(String classificazione) {
		this.classificazione = classificazione;
	}
	
	//Anno
	public int getAnno() {
		return anno;
	}
	public void setAnno(int anno) {
		this.anno = anno;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Libro [id=");
		builder.append(id);
		builder.append(", titolo=");
		builder.append(titolo);
		builder.append(", autore=");
		builder.append(autore);
		builder.append(", editore=");
		builder.append(editore);
		builder.append(", classificazione=");
		builder.append(classificazione);
		builder.append(", anno=");
		builder.append(anno);
		builder.append("]");
		return builder.toString();
	}
	
	
	//ToString 
	
	
	
}
