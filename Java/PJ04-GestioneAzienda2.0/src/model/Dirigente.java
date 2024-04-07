package model;

public class Dirigente extends Dipendente {
	
	private double pagaBase;
	
	public Dirigente(String nome, String cognome) {
		super(nome, cognome);
		this.ruolo = "Dirigente";
	}

	@Override
	public void calcolaStipendio() {
		this.stipendio = pagaBase;
	}

	public double getPagaBase() {
		return pagaBase;
	}

	public void setPagaBase(double pagaBase) {
		this.pagaBase = pagaBase;
	}
	
}
