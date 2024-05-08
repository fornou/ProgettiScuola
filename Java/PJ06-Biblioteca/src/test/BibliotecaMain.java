package test;

import java.util.Scanner;

import controller.Biblioteca;
import model.Libro;

public class BibliotecaMain {

	public static void main(String[] args) {
		
		Biblioteca biblio = new Biblioteca();
		Scanner t = new Scanner(System.in);
		int scelta = 1;
		
		while(scelta != 0) {
			
			menu();
			scelta = t.nextInt();
			
			switch (scelta) {
			case 1:
				//System.out.println("Aggiungi libro");
				Libro l = creaLibro();
				System.out.println("Aggiunto libro correttamente");
				System.out.println(l.getDescrizione());
				biblio.addLibro(l);
				break;
			case 2:
				System.out.println("Numero libri");
				System.out.println("I libri in biblioteca sono: "+ biblio.contaLibri());
				break;
			case 3:
				System.out.println("Elenco libri");
				for (Libro librettino : biblio.getLibri()) {
					System.out.println(librettino.getDescrizione());
				}
				biblio.getLibri();
				break;
				
			case 0:
				break;
	
			default:
				System.out.println("Non c'è l'opzione disponibile");
				break;
			}
			t.nextLine();
			System.out.println("\033[2J");
			
		}
		System.out.println("Programma eseguito correttamente!");
	}
	
	private static void menu() {
		System.out.println("Biblioteca Civica");
		System.out.println("-----------------");
		System.out.println("1 - Add Libro");
		System.out.println("2 - Count Libri");
		System.out.println("3 - List Libro");
		System.out.println("0 - Exit");
		System.out.println("-----------------");
		System.out.println("Fai la tua scelta");
	}
	
	private static Libro creaLibro() {
		Scanner s = new Scanner(System.in);
		Libro l = new Libro();
		System.out.println("Dammi il titolo:");
		String titolo = s.nextLine();
		System.out.println("Dammi l'autore:");
		String autore = s.nextLine();
		l.setTitolo(titolo);
		l.setAutore(autore);
		return l;
	}

}
