package repos;

import java.util.List;

import model.Corso;
import model.Student;

public interface CorsoDAO {

	String FIND_ALL = "Select * from corsi ";
	String FIND_BY_ID = FIND_ALL + "where codcorso = ?";
	
	List<Corso> findAll();
	Corso findById(int id);
}
