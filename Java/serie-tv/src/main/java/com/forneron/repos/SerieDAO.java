package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.forneron.entities.Serie;

@Repository
public interface SerieDAO extends JpaRepository<Serie, Long> {

}
