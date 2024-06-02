package db;

import java.util.List;

import model.Categoria;
import model.Piatto;

public interface PiattoDAO {
	//implicitamente public e final
	String FIND_ALL = "SELECT * FROM piatti";
	String ADD = "INSERT INTO piatti(nome, prezzo, tipo_piatto_id) VALUES (?, ?, ?)";
	String FIND_ONE = FIND_ALL + " where id = ?";
	
	//implicitamente public abstract
	List<Piatto> getPiatti();
	void addPiatto(Piatto p);
	Piatto getPiattoById(int id);
	
	
}
