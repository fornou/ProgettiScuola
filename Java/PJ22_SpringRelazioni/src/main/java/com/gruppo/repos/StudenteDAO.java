package com.gruppo.repos;

import org.springframework.data.jpa.repository.JpaRepository;

import com.gruppo.entities.Studente;

public interface StudenteDAO extends JpaRepository<Studente, Long>{

}
