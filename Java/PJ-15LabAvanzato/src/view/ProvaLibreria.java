package view;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import controller.Libreria;
import model.Libro;

/*class ComparatorePrezzo implements Comparator<Libro>{
	@Override
	public int compare(Libro o1, Libro o2) {
		return Double.compare(o2.getPrezzo(), o1.getPrezzo());
	}
}*/

public class ProvaLibreria {

	public static void main(String[] args) {
	
		Libreria feltrinelli = new Libreria("Feltrinelli");
		
		feltrinelli.addLibro("Zanna bianca", 122);
		feltrinelli.addLibro("Anna bianca", 104, 7);
		feltrinelli.addLibro("Panda bianca", 40, 12);
		
		List<Libro> libri = feltrinelli.getLibri();
		
		/*Comparator<Libro> cp = new Comparator<Libro>() {
			@Override
			public int compare(Libro o1, Libro o2) {
				return Double.compare(o2.getPrezzo(), o1.getPrezzo());
			}
		};*/
		//ComparatorePrezzo cp = new ComparatorePrezzo();
		//Collections.sort(libri, new ComparatorePrezzo());
		//Collections.sort(libri);// richiama il metodo compareTo
		
		libri
		.stream()
		.sorted((lib1, lib2)->lib2.getPagine()-lib1.getPagine())
		.forEach(l -> System.out.println(l));
		
		//for(Libro l : libri) {
			//System.out.println(l.getTitolo() + l.getPrezzo());
		//}
		
	
	}

}
