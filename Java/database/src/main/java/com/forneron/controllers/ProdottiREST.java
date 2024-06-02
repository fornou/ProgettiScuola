package com.forneron.controllers;

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
import com.forneron.services.ProdottoService;

@RestController
@RequestMapping(path={"", "api"})
public class ProdottiREST {
	
	@Autowired
	private ProdottoService service;
	
	@GetMapping("prodotti")
	public List<Prodotto> getProdotti(){
		return service.getProdotti();
	}
	
	@GetMapping("prodotti/{id}")
	public Prodotto getProdotto(@PathVariable int id){//se match se no mettere ()
		return service.getProdottoById(id);
	}
	
	@PostMapping("prodotti")
	public Prodotto addProdotto(@RequestBody Prodotto p) {
		return service.addProdotto(p);
	}
	
	@PostMapping("moltiprodotti")
	public List<Prodotto> addProdotto(@RequestBody List<Prodotto> p) {
		
		for(Prodotto prod: p){
			service.addProdotto(prod);
		}
		return service.getProdotti();
	}
	
	@PutMapping("prodotti")
	public Prodotto updateProdotto(@RequestBody Prodotto p) {
		return service.updateProdotto(p);
	}

	@DeleteMapping("prodotti")
	public ResponseEntity<String> deleteProdotto(@RequestBody Prodotto p) {
		service.deleteProdotto(p);
		return new ResponseEntity<>(
				"Hai Eliminato correttamente il prodotto",
				HttpStatus.OK);
	}
	
	
}
