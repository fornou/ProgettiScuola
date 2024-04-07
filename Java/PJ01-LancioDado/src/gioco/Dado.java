package gioco;

public class Dado {
	int facce = 6, facciaUscita = 1;
	
	public void cambiaFaccia() {
		facciaUscita = (int)(Math.random() * facce) + 1;
	}
}
