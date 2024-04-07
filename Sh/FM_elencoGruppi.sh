#!/bin/bash

# Ottieni la lista dei gruppi e visualizzala in ordine alfabetico
gruppi=$(cut -d: -f1 /etc/group | sort)

# Stampa la lista dei gruppi
echo "Elenco dei gruppi nel sistema:"
echo "$gruppi"