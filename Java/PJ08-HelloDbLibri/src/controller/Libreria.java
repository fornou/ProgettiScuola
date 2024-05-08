package controller;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import database.Connessione;
import model.Libro;

public class Libreria {
	
	private ArrayList<Libro> libri;
	
	public Libreria() {
		libri = new ArrayList<Libro>();
	}
	
	public ArrayList<Libro> getLibri(){
		return libri;
	}
	
	public void riempiLibreriaDaDb() throws SQLException {
		Connessione c = new Connessione();
		c.connetti();
		Connection conn = c.getConn();
		
		String query = "SELECT * FROM libri;";
		
		Statement contenitoreQuery = conn.createStatement();
		
		ResultSet risultatiQuery = contenitoreQuery.executeQuery(query);
		
		while(risultatiQuery.next()) {
			//int id= risultatiQuery.getInt("id");
			//Libro l = new Libro(id);
			Libro l = new Libro();
			l.setId(risultatiQuery.getInt("id"));
			l.setTitolo(risultatiQuery.getString("Titolo"));
			l.setAutore(risultatiQuery.getString("Autore"));
			l.setEditore(risultatiQuery.getString("Editore"));
			l.setClassificazione(risultatiQuery.getString("Classificazione"));
			l.setAnno(risultatiQuery.getInt("Anno"));
			//System.out.println(l);
			libri.add(l);
		}
	}
	//public void leggiLibri() {
		//for (Libro libro : libri) {
			//System.out.println(libro);
		//}
	//}
	
	
}
