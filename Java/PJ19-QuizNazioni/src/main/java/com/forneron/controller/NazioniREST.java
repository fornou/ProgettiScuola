package com.forneron.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
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

}
