package file;

public class Canzone {
	String titolo, cantanti;
	
	public Canzone(String titolo, String cantanti) {
		this.titolo = titolo;
		this.cantanti = cantanti;
	}
	public String stampa() {
		if(cantanti == null) {
			return "Manca un elemento";
		}else{
			return "La canzone "+ titolo+ " è cantata da " + cantanti;
		}
	}
}
