package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.City;
import com.forneron.entities.Country;
import com.forneron.repos.CityDAO;
import com.forneron.repos.CountryDAO;

@Service//specifica il servizio
public class WorldServiceImpl implements WorldService{
	
	@Autowired
	private CountryDAO countryDAO;
	@Autowired//Gestisce la creazione dell'oggetto
	private CityDAO cityDAO;
	
	@Override
	public List<Country> getCountries() {
		// TODO Auto-generated method stub
		return countryDAO.findAll();
	}

	@Override
	public List<City> getCities() {
		// TODO Auto-generated method stub
		return cityDAO.findAll();
	}

	@Override
	public Country getCountryByCode(String code) {
		// TODO Auto-generated method stub
		return countryDAO.getReferenceById(code);
	}

	@Override
	public City getCityById(int id) {
		// TODO Auto-generated method stub
		return cityDAO.getReferenceById(id);
	}

}
