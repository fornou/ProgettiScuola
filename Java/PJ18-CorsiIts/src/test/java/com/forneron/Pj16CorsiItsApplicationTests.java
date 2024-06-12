package com.forneron;


import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import com.forneron.entities.LibrettoUniversitario;
import com.forneron.entities.Studente;
import com.forneron.services.ITSService;

@SpringBootTest
class Pj16CorsiItsApplicationTests {
	
	@Autowired 
	private ITSService service;

	@Test
	void contextLoads() {
		
		Studente s = new Studente();
		LibrettoUniversitario lu = new LibrettoUniversitario();
		
		lu.setNumeroMatricola("ABC!123");
		lu.setStudente(s);
		s.setNome("mattia");
		s.setLibrettoUniversitario(lu);
		
		service.addStudente(s);
		service.addLibretto(lu);
		
		Assertions.assertEquals(1, service.getStudenti().size());
		
	}

}
