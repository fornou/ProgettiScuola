package com.forneron;

import java.util.List;

import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import com.forneron.entities.City;
import com.forneron.entities.Country;
import com.forneron.services.WorldService;

@SpringBootTest
class WorldApplicationTests {
	
	@Autowired
	private WorldService service;
		
	@Test
	@Order(1)
	void getCountries() {
		List<Country> countries = service.getCountries();
		System.out.println("I paesi sono: "+ countries.size());
	}
	
	@Test
	@Order(2)
	void getCities() {
		List<City> cities = service.getCities();
		System.out.println("I paesi sono: "+ cities.size());
	}

}
