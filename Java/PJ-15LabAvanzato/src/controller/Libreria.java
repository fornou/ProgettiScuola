package controller;

import java.util.ArrayList;
import java.util.List;

import model.Libro;

public class Libreria {
	
	List<Libro> libri;
	String nome;
	
	public Libreria(String nome){
		this.nome = nome;
		this.libri = new ArrayList<Libro>();
	}
	
	public void addLibro(String titolo, int pagine, double prezzo) {
		Libro l = new Libro();
		l.setTitolo(titolo);
		l.setPagine(pagine);
		l.setPrezzo(prezzo);
		libri.add(l);
	}
	
	public void addLibro(String titolo, int pagine) {
		this.addLibro(titolo, pagine, 0);
	}
	
	public void addLibro(Libro l) {
		libri.add(l);
	}
	
	public List<Libro> getLibri(){
		return libri;
	}
}
