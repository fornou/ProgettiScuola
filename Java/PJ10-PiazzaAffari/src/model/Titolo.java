package model;

public class Titolo {
	private int id, capitaleMLN;
	private String nomeTitolo, raccomandazione;
	
	public Titolo() {
		
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getCapitaleMLN() {
		return capitaleMLN;
	}

	public void setCapitaleMLN(int capitaleMLN) {
		this.capitaleMLN = capitaleMLN;
	}

	public String getNomeTitolo() {
		return nomeTitolo;
	}

	public void setNomeTitolo(String nomeTitolo) {
		this.nomeTitolo = nomeTitolo;
	}

	public String getRaccomandazione() {
		return raccomandazione;
	}

	public void setRaccomandazione(String raccomandazione) {
		this.raccomandazione = raccomandazione;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Titolo [id=");
		builder.append(id);
		builder.append(", capitaleMLN=");
		builder.append(capitaleMLN);
		builder.append(", nomeTitolo=");
		builder.append(nomeTitolo);
		builder.append(", raccomandazione=");
		builder.append(raccomandazione);
		builder.append("]");
		return builder.toString();
	}
	
	
	
	
}
