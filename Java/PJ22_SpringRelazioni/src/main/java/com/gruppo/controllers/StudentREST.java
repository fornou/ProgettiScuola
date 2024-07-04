package com.gruppo.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.gruppo.entities.Corso;
import com.gruppo.entities.Libretto;
import com.gruppo.entities.Studente;
import com.gruppo.services.StudentiService;
import org.springframework.web.bind.annotation.PostMapping;


@RestController
@RequestMapping("api")
public class StudentREST {
	@Autowired
	private StudentiService service;
	
	@GetMapping("studenti")
	public List<Studente> getStudenti(){
		return service.getStudenti();
	}
	@GetMapping("corsi")
	public List<Corso> getCorsi(){
		return service.getCorsi();
	}
	@GetMapping("libretti")
	public List<Libretto> getLibretti(){
		return service.getLibretti();
	}
	@PostMapping("aggiungi/studente")
	public void addStudente(Studente s){
		service.addStudente(s);
	}
	@PostMapping("aggiungi/corso")
	public void addStudente(Corso s){
		service.addCorso(s);
	}
	@PostMapping("aggiungi/libretto")
	public void addStudente(Libretto s){
		service.addLibretto(s);
	}	
}
