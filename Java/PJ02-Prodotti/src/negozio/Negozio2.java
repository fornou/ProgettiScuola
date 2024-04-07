package negozio;
import utili.Utl;

public class Negozio2 {
	public static void main(String[] args) {

	    Utl.prntString("Quanti prodotti vuoi comprare?");
	    String coseDaComprare = Utl.in.nextLine();	    
	    
	    Utl.prntString("Hai detto che vuoi comprare:");
	    Utl.prntString(coseDaComprare);
	}
}
