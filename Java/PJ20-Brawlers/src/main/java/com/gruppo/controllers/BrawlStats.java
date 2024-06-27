package com.gruppo.controllers;

import java.util.List;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.gruppo.entities.Brawler;
import com.gruppo.services.BrawlerService;

@RestController
@RequestMapping("api")
@CrossOrigin
public class BrawlStats {
	@Autowired
	private BrawlerService service;
	
	@GetMapping("brawlers")
	public ResponseEntity<List<Brawler>> getBrawler(){
		return new ResponseEntity<List<Brawler>>(service.getAllBrawlers(), HttpStatus.OK);
		
	}
	
	@GetMapping("brawlers/rarity/{rarity}")
	public ResponseEntity<List<Brawler>> getBrawlersByRarity(@PathVariable String rarity){
		return new ResponseEntity<List<Brawler>>(service
				.getAllBrawlersByRarity(rarity), HttpStatus.OK);
	}
	
	@GetMapping("brawlers/carattere/{carattere}")
	public ResponseEntity<List<Brawler>> getBrawlersByCarattere(@PathVariable String carattere){
		return new ResponseEntity<List<Brawler>>(service
				.getAllBrawlersByCarattere(carattere), HttpStatus.OK);
	}
	
	@GetMapping("brawlers/{id}")
	public ResponseEntity<Brawler> getBrawler(@PathVariable int id){
		
		if(service.getBrawler(id) != null) {
			return new ResponseEntity<Brawler>(service
					.getBrawler(id), HttpStatus.OK);
		}
		return new ResponseEntity<Brawler>(new Brawler(), HttpStatus.NOT_FOUND);
	}
	
	@GetMapping("brawlers/rarity")
	public ResponseEntity<Set<String>> getRarities(){
		return new ResponseEntity<Set<String>>(service.
				getRarities(), HttpStatus.OK);
		
	}
	
	@GetMapping("brawlers/carattere")
	public ResponseEntity<List<String>> getCaratteri(){
		return new ResponseEntity<List<String>>(service.
				getCaratteri(), HttpStatus.OK);
		
	}
	
	
}
