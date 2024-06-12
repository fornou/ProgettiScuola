package com.forneron.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.forneron.entities.LibrettoUniversitario;
import com.forneron.entities.Pokemon;
import com.forneron.entities.Studente;
import com.forneron.services.ITSService;

@RestController
@RequestMapping("api")
public class ITSRest {
	
	@Autowired
	private ITSService service;
	
	@GetMapping("/studenti")
	public List<Studente> getStudenti(){
		return service.getStudenti();
	}
	
	@GetMapping("/studenti/{id}")
	public ResponseEntity<Studente> getStudente(@PathVariable int id){
		Studente studenteById = service.getStudenteById(id);
		
		if(studenteById==null) {
			new ResponseEntity<Studente>(new Studente(), HttpStatus.NOT_FOUND);
		}
		return new ResponseEntity<Studente>(studenteById, HttpStatus.OK);
	}
	
	@GetMapping("/libretti")
	public List<LibrettoUniversitario> getLibretti(){
		return service.getLibretti();
	}
	
	@GetMapping("/pokemon")
	public List<Pokemon> getPokemon(){
		return service.getPokemon();
	}
	
	@GetMapping("/libretti/{id}")
	public LibrettoUniversitario getLibretto(@PathVariable int id){
		return service.getLibretto(id);
	}
	
	@PostMapping("/studenti")
	public ResponseEntity<Studente> addStudente(@RequestBody Studente s) {
		
		s.getLibrettoUniversitario().setStudente(s);
		
		return new ResponseEntity<Studente>( service.addStudente(s), HttpStatus.CREATED);
	}
	
	
	
}
