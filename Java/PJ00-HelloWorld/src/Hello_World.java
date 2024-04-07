import utili.Utl;

public class Hello_World {

	public static void main(String [] args) throws InterruptedException {
		Utl.cls();
		String parola = "CIAO mondo", alfabeto = "abcdefghijklmnopqrstuvxywz ,?", saluto = "";
		char lettPar, lettAlf, lettAlfMaiusc;
		boolean trov;
		 
		for(int i = 0; i < parola.length(); i ++)
		{
			lettPar = parola.charAt(i);
			trov = false;
			for(int j = 0; j < alfabeto.length() && trov == false; j++)
			{
				lettAlf = alfabeto.charAt(j);
				lettAlfMaiusc = Character.toUpperCase(lettAlf);
				if(lettPar == lettAlf || lettPar == lettAlfMaiusc) {
					saluto += lettPar;
					trov = true;
				}
				Utl.prntString(saluto+lettAlf);
				Thread.sleep(50);
				Utl.cls();
			}
			Utl.cls();
		}
        Utl.prntString(saluto);                    
        Utl.pause();
        Utl.cls();
        
	}
}
