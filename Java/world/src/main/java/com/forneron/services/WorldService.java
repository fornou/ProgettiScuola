package com.forneron.services;

import java.util.List;

import com.forneron.entities.City;
import com.forneron.entities.Country;

public interface WorldService {
	
	List<Country> getCountries();
	List<City> getCities();
	
	Country getCountryByCode(String code);
	City getCityById(int id);
}
