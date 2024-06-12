package com.forneron.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.forneron.entities.Prodotto;
import com.forneron.sevices.ProdottiService;

@RestController
@RequestMapping("api")
public class ProdottiREST {

	@Autowired
	ProdottiService service;
	
	@GetMapping("prodotti")
	List<Prodotto>getProdotti(){
		return service.getProdotti();
	}
	
	@GetMapping("prodotti/{id}")
	Prodotto getProdottoById(@PathVariable int id){
		return service
			.getProdotti()
			.stream()
			.filter(p->p.getId()==id)
			.findFirst()
			.get();
	}
	
	@GetMapping("prodotti/{minimo}/{massimo}")
	List<Prodotto>getProdottiByPrice(@PathVariable("minimo") double min,@PathVariable("massimo") double max){
		return service.getProdottiByPrice(min, max);
	}
	
	@PostMapping("prodotti")
	Prodotto addProdotto(@RequestBody Prodotto p) {
		return service.addProdotto(p);
	}
	
	@PostMapping("tanti-prodotti")
	List<Prodotto> addProdotti(@RequestBody List<Prodotto> p) {
		
		for(Prodotto prodotto : p) {
			service.addProdotto(prodotto);
		}
		return service.getProdotti();
	}
	
	@PutMapping("prodotti")
	Prodotto updateProdotto(@RequestBody Prodotto p) {
		return service.updateProdotto(p);
	}
	
	@DeleteMapping("prodotti")
	ResponseEntity<Prodotto> deleteProdotto(@RequestBody Prodotto p) {
		 service.updateProdotto(p);
		 return new ResponseEntity<>(null, HttpStatus.I_AM_A_TEAPOT);
	}
	
}
