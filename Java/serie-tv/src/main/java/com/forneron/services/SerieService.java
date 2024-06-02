package com.forneron.services;

import java.util.List;

import com.forneron.entities.Serie;

public interface SerieService {
	List<Serie> getSerie();
	Serie getSerieById(long id);
	Serie addSerie(Serie s);
	Serie updateSerie(Serie s);
	void deleteSerie(Serie s);
	void deleteSerie(long id);
}
