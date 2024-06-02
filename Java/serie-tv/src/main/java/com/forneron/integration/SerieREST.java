package com.forneron.integration;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.forneron.entities.Serie;
import com.forneron.services.SerieService;

@RestController
@RequestMapping("api/serie")
public class SerieREST {
	
	@Autowired
	private SerieService service;
	
	@GetMapping("getAll")
	public List<Serie> getAll(){
		return service.getSerie();
	}
	
	@PostMapping("addSerie")
	public Serie addSerie(@RequestBody Serie s){
		return service.addSerie(s);
	}
	

}
