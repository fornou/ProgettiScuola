package repos;

import java.util.List;

import model.Student;

public interface StudentDAO {

	String FIND_ALL = "Select * from studenti";
	String FIND_BY_ID = FIND_ALL + " where id = ?";
	
	List<Student> findAll();
	Student findById(int id);
}
