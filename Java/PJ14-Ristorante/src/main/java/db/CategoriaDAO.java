package db;

import java.util.List;

import model.Categoria;

public interface CategoriaDAO {
	
	String FIND_ALL = "Select * from tipi_piatto";
	String FIND_ONE = FIND_ALL + " where id = ?";
	
	List<Categoria> getCategorie();
	Categoria getCategoriaById(int id);
}
