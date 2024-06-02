package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;

import com.forneron.entities.City;

public interface CityDAO extends JpaRepository<City, Integer>{
	
}
