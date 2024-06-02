package com.forneron.services;

import java.util.List;

import com.forneron.entities.Film;

public interface FilmService {
	
	List<Film> getFilm();
	Film getFilmById(int id);
	Film addFilm(Film f);
}
