package its;

public class Azienda {
	private Impiegato [] impiegati;
	private int massimo, attuale;
	
	public Azienda(int massimo) {
		this.massimo = massimo;
		this.impiegati = new Impiegato[massimo];
		this.attuale = 0;
	}

	public void addImpiegato(Impiegato i) {
		this.impiegati[attuale] = i;
		this.attuale ++;	
	}
	
	public int getAttuale() {
		return this.attuale;
	}
	
	public int getMassimo() {
		return this.massimo;
	}
	
	public int calcolaStipendi() {
		int totale = 0;
		
		for (int i = 0; i < impiegati.length; i++) {
			if (impiegati[i] != null) {
				totale += impiegati[i].getStipendio();
			}
		}
		
		return totale;
	}
	
	public String stampaDipendenti() {
		StringBuilder sb = new StringBuilder();
		for (Impiegato impiegato : impiegati) {
			sb.append(impiegato);
			sb.append("\n-----------\n");
		}
		return sb.toString();
	}
	
	public String stampaDipendenti2() {
		StringBuilder sb = new StringBuilder();
		for (Impiegato impiegato : impiegati) {
			sb.append("<li>");
			sb.append(impiegato.getNome());
			sb.append("</li>");
		}
		return sb.toString();
	}
	
}


