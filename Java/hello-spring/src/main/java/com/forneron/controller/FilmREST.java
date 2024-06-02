package com.forneron.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.forneron.entities.Film;
import com.forneron.services.FilmService;

@RestController
public class FilmREST {
	
	@Autowired
	private FilmService fs;
	
	@GetMapping("api/film")
	public List<Film> getAll(){
		return fs.getFilm();
	}
	
	@PostMapping("api/film")
	public Film addFilm(@RequestBody Film f){
		return fs.addFilm(f);
	}
}
