package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;

import com.forneron.entities.Country;

public interface CountryDAO extends JpaRepository<Country, String>{

}
