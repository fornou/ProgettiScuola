package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.forneron.entities.Pokemon;
import java.util.List;


@Repository
public interface PokemonDAO extends JpaRepository<Pokemon, String>{
	 List<Pokemon> findByNameContaining(String name);
}
