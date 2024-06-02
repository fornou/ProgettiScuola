package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.Serie;
import com.forneron.repos.SerieDAO;

@Service
public class SerieServiceImpl implements SerieService{

	@Autowired
	private SerieDAO serieDao;
	
	
	@Override
	public List<Serie> getSerie() {
		return serieDao.findAll();
	}

	@Override
	public Serie getSerieById(long id) {
		return serieDao.getReferenceById(id);
		
	}

	@Override
	public Serie addSerie(Serie s) {
		return serieDao.save(s);
	}

	@Override
	public Serie updateSerie(Serie s) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void deleteSerie(Serie s) {
		serieDao.delete(s);
	}

	@Override
	public void deleteSerie(long id) {
		serieDao.deleteById(id);
		
	}

}
