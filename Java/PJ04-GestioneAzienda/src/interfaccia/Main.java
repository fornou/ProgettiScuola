package interfaccia;

import java.util.Scanner;

import its.Azienda;
import its.Impiegato;

public class Main {
	public static void main(String[] args) {
		
		boolean gira = true;
		int dipendenti = 0;
		Scanner in = new Scanner (System.in);
		Azienda generica = null;
		
		while(gira) {
			System.out.println("cosa vuoi fare?");
			System.out.println("A - Crea azienda");
			System.out.println("B - Aggiungi dipendente");
			System.out.println("C - Calcola stipendi");
			System.out.println("D - Lista dipendenti");
			System.out.println("X - Esci");
			String risposta = in.nextLine();
			risposta = risposta.toUpperCase();
			switch(risposta) {
				case "A":
					System.out.println("Quanti dipendenti vuoi?");
					dipendenti = in.nextInt();
					in.nextLine();
					generica = new Azienda(dipendenti);
					break;
				case "B":
					if(generica != null && generica.getAttuale() < generica.getMassimo()) {
						System.out.println("Nome dipendente");
						String nome = in.nextLine();
						System.out.println("Cognome dipendente");
						String cognome = in.nextLine();
						System.out.println("Anno di nascita dipendente");
						int anno = in.nextInt();
						in.nextLine();
						Impiegato i = new Impiegato(nome, cognome, anno);
						System.out.println("Qual'è lo stipendio del dipendente");
						int stipendio = in.nextInt();
						in.nextLine();
						i.setStipendio(stipendio);
						generica.addImpiegato(i);
					}else {
						System.out.println("{ERR}");
					}
					break;
				case "C":
					if(generica != null) {
						System.out.println("Lo stipendio totale è: ");
						System.out.println(generica.calcolaStipendi());
					}
					break;
					
				case "D":
					if(generica != null) {
						//System.out.println("<h1>L'elenco dei dipendenti:</h1>");
						//System.out.println("<ul>");
						//System.out.println(generica.stampaDipendenti2());
						//System.out.println("</ul>");
						System.out.println("L'elenco dei dipendenti:");
						System.out.println(generica.stampaDipendenti());
					}
					break;
				case "X":
					
					gira = false;
					break;
				default:
					System.out.println("Non compreso");
					break;
			}
		}
		
		System.out.println("Sei uscito dal tunnel");
		
	}
}
;