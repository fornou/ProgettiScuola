package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;

import com.forneron.entities.Studente;

public interface StudenteDAO extends JpaRepository<Studente, Long>{

}
