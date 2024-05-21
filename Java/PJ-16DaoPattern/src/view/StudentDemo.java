package view;

import java.util.List;

import model.Student;
import repos.StudentDAO;
import repos.StudentDAOImpl;

public class StudentDemo {

	public static void main(String[] args) {
		
		StudentDAO dao = new StudentDAOImpl();
		
		List<String> listaCognomi= dao.findAll()
			.stream()//diventa un flusso
			/*.filter(
					s -> s.getNome()
					.endsWith("o"))
			.filter(
					s -> s.getCognome()
					.startsWith("R"))*/
			.map(s -> s.getCognome())
			.toList();
			
		
		listaCognomi.forEach(System.out::println);
		
		
		Student f = dao.findById(1002);
		
		System.out.println(f);
		
	}

}
