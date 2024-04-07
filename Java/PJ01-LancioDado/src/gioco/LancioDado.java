package gioco;
import utili.Utl;

public class LancioDado {
    public static void main(String[] args) {
        Utl.cls();
        
        Dado d0 = new Dado();
        Dado d1 = new Dado();
        
        final int NUMERO_LANCI = 10000;
        int vittorie = 0;
        long start = System.currentTimeMillis(); 
        
        for (int i = 0; i < NUMERO_LANCI; i++) {
			d0.cambiaFaccia();
			d1.cambiaFaccia();
			
        	//System.out.println("Il dado 1 = " + d0.facciaUscita);
            //System.out.println("Il dado 2 = " + d1.facciaUscita);
            //System.out.println("________________________________");
            
            if(d0.facciaUscita == d1.facciaUscita) {
            	//System.out.println("Hai vinto!!\n");
            	vittorie++;
            }
		} 
        long stop = System.currentTimeMillis();
        System.out.println("Hai giocato " + NUMERO_LANCI);
        System.out.println("Hai vinto " + vittorie);
        double perc = (double)vittorie / NUMERO_LANCI * 100;
        System.out.println("La percentuale di vittoria è " + perc + "%");
        System.out.println("Il tempo impiegato: " + (stop - start));
        Utl.pause();
    }
}
