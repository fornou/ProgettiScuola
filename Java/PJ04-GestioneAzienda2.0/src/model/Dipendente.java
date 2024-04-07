package model;

public abstract class Dipendente {
	
	private static int matricolatore = 1;
	
	protected double stipendio;
	protected String nome, cognome;
	protected String ruolo;
	protected int nMatricola;
	
	public Dipendente(String nome, String cognome) {
		this.nMatricola = matricolatore++;
		this.nome = nome;
		this.cognome = cognome;
	}
	
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Dipendente [stipendio=");
		builder.append(stipendio);
		builder.append(", nome=");
		builder.append(nome);
		builder.append(", cognome=");
		builder.append(cognome);
		builder.append(", ruolo=");
		builder.append(ruolo);
		builder.append(", nMatricola=");
		builder.append(nMatricola);
		builder.append("]");
		return builder.toString();
	}

	public int getnMatricola() {
		return nMatricola;
	}

	public double getStipendio() {
		return stipendio;
	}

	public void setStipendio(double stipendio) {
		this.stipendio = stipendio;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCognome() {
		return cognome;
	}

	public void setCognome(String cognome) {
		this.cognome = cognome;
	}

	public String getRuolo() {
		return ruolo;
	}

	public void setRuolo(String ruolo) {
		this.ruolo = ruolo;
	}

	public abstract void calcolaStipendio(); // senza corpo
	
}
