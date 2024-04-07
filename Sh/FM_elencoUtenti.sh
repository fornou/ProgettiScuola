#!/bin/bash

# Ottieni la lista degli utenti e visualizzala in ordine alfabetico
utenti=$(cut -d: -f1 /etc/passwd | sort)

# Stampa la lista degli utenti
echo "Elenco degli utenti del sistema:"
echo "$utenti"