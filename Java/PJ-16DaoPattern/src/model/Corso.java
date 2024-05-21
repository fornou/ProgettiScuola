package model;

public class Corso {
	
	private int codCorso;
	private String nome;
	
	public int getCodCorso() {
		return codCorso;
	}
	public void setCodCorso(int codCorso) {
		this.codCorso = codCorso;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Corso [codCorso=");
		builder.append(codCorso);
		builder.append(", nome=");
		builder.append(nome);
		builder.append("]");
		return builder.toString();
	}

	
	
	
}
