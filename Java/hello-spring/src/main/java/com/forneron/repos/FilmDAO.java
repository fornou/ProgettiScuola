package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.forneron.entities.Film;
@Repository//opzionale
public interface FilmDAO extends JpaRepository<Film, Integer>{
	
}
