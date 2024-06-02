package com.forneron.presentation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import com.forneron.entities.Serie;
import com.forneron.services.SerieService;

@Controller
public class SerieMVC {
	@Autowired
	private SerieService service;
	
	@GetMapping("")
	public String home() {
		return "index";
	}
	
	@GetMapping("serie")
	public String getSerie(Model m) {
		m.addAttribute("elencoSerie", service.getSerie());
		return "elencoSerie";
	}
	
	@GetMapping("add/serie")
	public String addSerie() {
		return "aggiungiSerie";
	}
	
	@PostMapping("add/serie")
	public String addSerie(Serie s) {
		service.addSerie(s);
		return "redirect:serie";
	}
	
	
}
