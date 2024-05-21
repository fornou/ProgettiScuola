package db;

import java.util.List;

import model.Piatto;

public interface PiattoDAO {
	//implicitamente public e final
	String FIND_ALL = "SELECT * FROM piatti";
	String ADD = "INSERT INTO piatti(nome, prezzo, tipo_piatto_id) VALUES (?, ?, ?)";
	
	//implicitamente public abstract
	List<Piatto> getPiatti();
	void addPiatto(Piatto p);
	
	
}
