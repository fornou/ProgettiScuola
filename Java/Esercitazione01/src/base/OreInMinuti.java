package base;
import utili.Utl;

public class OreInMinuti {
	public static void main(String[] args) {
		try {
			Utl.prntString("numero ore lavorate");
			double ore = Utl.in.nextDouble();			
			int minuti = (int)(ore * 60);
			
			System.out.printf("Le ore: %f\tI minuti: %d\n", ore, minuti);
		}catch(Exception e) {
			Utl.prntString("Qualcosa non è andato");
		}
		Utl.prntString("Game Over");
		
		Utl.in.close();
	}
}
