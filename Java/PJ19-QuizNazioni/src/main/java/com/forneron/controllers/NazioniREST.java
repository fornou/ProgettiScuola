package com.forneron.controller;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.forneron.entities.Nazione;
import com.forneron.services.NazioniService;

@RestController
@RequestMapping("api")
public class NazioniREST {
	
	@Autowired
	NazioniService service;
	
	@GetMapping("nazioni")
	List<Nazione>getNazioni(){
		return service.getNazioni();
	}
	
	@GetMapping("nazioni/{alphacod}")
	public ResponseEntity<Nazione> getNazione(@PathVariable String alphacod){
		Optional<Nazione> nazioneById = service.getNazioneByCode(alphacod);
		
		if (nazioneById.isPresent()) {
	        return ResponseEntity.ok(nazioneById.get());
	    } else {
	        return ResponseEntity.notFound().build();
	    }
	}
	
	@GetMapping("nazioni/{minimo}/{massimo}")
	List<Nazione> getNazioneByPopolazione(@PathVariable("minimo") int min,@PathVariable("massimo") int max){
		return service.getNazioniByPopolazione(min, max);
	}
	
	@GetMapping("continenti")
	private List<String> getRegioniDistinte(){
		 return service.getRegioniDistinte();
	}
}
