package view;

import java.time.LocalDate;
import java.util.List;

import model.Esame;
import repos.CorsoDAO;
import repos.CorsoDAOImpl;
import repos.EsameDAO;
import repos.EsameDAOImpl;
import repos.StudentDAO;
import repos.StudentDAOImpl;

public class EsamiDemo {
	public static void main(String[] args) {
		
		EsameDAO dao= new EsameDAOImpl();
		StudentDAO daoStudenti = new StudentDAOImpl();
		CorsoDAO daoCorsi = new CorsoDAOImpl();
		
		List<Esame> esami = dao.getAll();
		
		esami.forEach(System.out::println);
		
		/*Esame e = new Esame();
		
		e.setVoto(30);
		e.setData(LocalDate.now());
		e.setStudente(daoStudenti.findById(3));
		e.setCorso(daoCorsi.findById(3));
		
		dao.addEsame(e);*/
	}
}
