package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.Film;
import com.forneron.repos.FilmDAO;

@Service
public class FilmServiceImpl implements FilmService{
	@Autowired
	private FilmDAO filmDao;
	
	@Override
	public List<Film> getFilm() {
		return filmDao.findAll();
	}

	@Override
	public Film getFilmById(int id) {
		return null;
		//return filmDao.findById(id);
	}

	@Override
	public Film addFilm(Film f) {
		return filmDao.save(f);
	}

}
