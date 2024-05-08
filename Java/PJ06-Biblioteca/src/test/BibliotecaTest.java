package test;

import java.util.ArrayList;

import controller.Biblioteca;
import model.Libro;

public class BibliotecaTest {
	public static void main(String[] args) {
		Biblioteca civica = new Biblioteca();
		Biblioteca nazionale = new Biblioteca();
		
		Libro libro1 = new Libro();
		libro1.setTitolo("Il Barone Rampante");
		libro1.setAutore("Calvino");
		
		Libro libro2 = new Libro("I Malavoglia");
		libro1.setAutore("Verga");
		
		Libro libro3 = new Libro("I Robot", "Asimov");
		
		civica.addLibro(libro1);
		civica.addLibro(libro2);
		civica.addLibro(libro3);
		civica.addLibro(libro1);
		civica.addLibro(libro2);
		civica.addLibro(libro3);
		
		nazionale.addLibro(libro1);
		nazionale.addLibro(libro2);
		nazionale.addLibro(libro3);
		nazionale.addLibro(libro1);
		nazionale.addLibro(libro2);
		nazionale.addLibro(libro3);
		
		System.out.println("Libri alla biblioteca civica: "+ civica.contaLibri());
		
		System.out.println("Libri alla biblioteca nazionale: "+ nazionale.contaLibri());
		
		ArrayList<Libro> libriNazionali = nazionale.getLibri();
		ArrayList<Libro> libriCivici = civica.getLibri();
		
		System.out.println("Libri Nazionali");
		for (Libro libro : libriNazionali) {
			System.out.println(libro.getDescrizione());
		}
		System.out.println("Libri Civici");
		for (Libro libro : libriCivici) {
			System.out.println(libro.getDescrizione());
		}
		
	}
}
