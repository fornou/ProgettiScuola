package view;

import java.util.List;

import model.Corso;
import repos.CorsoDAO;
import repos.CorsoDAOImpl;

public class CorsoDemo {

	public static void main(String[] args) {
		
		CorsoDAO dao = new CorsoDAOImpl();
		
		List<String> listaCorsi= dao.findAll()
			.stream()//diventa un flus
			.map(s -> s.getNome())
			.toList();
			
		
		listaCorsi.forEach(System.out::println);
		
		Corso c = dao.findById(104);
		
		System.out.println(c);
	}

}
