package controller;

import java.util.ArrayList;

import model.Libro;

public class Biblioteca {
	private ArrayList<Libro> libri;
	
	public Biblioteca() {
		this.libri = new ArrayList<Libro>();
	}
	
	public void addLibro(Libro l) {
		this.libri.add(l);
	}
	
	public int contaLibri() {
		return libri.size();
	}
	
	public ArrayList<Libro> getLibri(){
		return libri;
	}
}
