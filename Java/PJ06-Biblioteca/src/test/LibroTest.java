package test;

import model.Libro;

public class LibroTest {

	public static void main(String[] args) {
		Libro libro1 = new Libro();
		Libro libro2 = new Libro("I Malavoglia");
		Libro libro3 = new Libro("I Robot", "Asimov");
		

		libro1.setTitolo("Il Barone Rampante");
		libro1.setAutore("Calvino");
		
		libro2.setAutore("Verga");
		
		System.out.println(libro1.getDescrizione());
		System.out.println(libro2.getDescrizione());
		System.out.println(libro3.getDescrizione());

	}

}
