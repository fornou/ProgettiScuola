package services;

import java.util.List;

import model.Categoria;
import model.Piatto;

public interface RistoranteServiceDAO {	
	List<Categoria> getCategorie();
	List<Piatto> getPiatti();
	
	Piatto getPiattoById(int id);
	Categoria getCategoriaById(int id);
	
	List<Piatto> getPiattiByCategoria(Categoria c);
}
