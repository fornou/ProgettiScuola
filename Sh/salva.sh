#!/bin/bash
#!percorso il percorso da backuppare
#!crea directory per backup nella home(controllare esistenza)
#!il nome del file sia  con data e ora dell'operazione (backup-20240219-115732.tar.gz)
#!dare conferma dell'operazione

backup_dir = "$HOME/Backup" #dove viene salvato il backup

printf "dammi il percorso %s\n" $USER
read dir_to_backup

# Controlla se esiste se no la crea
# -d flag per percorso
# then allora, esegui
if [ ! -d "$dir_to_backup" ]; then
    echo "Non esiste questo percorso.!"
    exit 1 #termina 
fi

if [ ! -d "$backup_dir" ]; then
    echo "Non esiste ancora. Verrà creata la cartella backup!"
    mkdir -p "$backup_dir" #-p
    exit 1 #termina 
fi

# Generate a filename with the current date and time
backup_file="backup-$(date +"%Y%m%d-%H%M%S").tar.gz"

# crea file tar
tar -czf "$backup_directory/$backup_file" "$dir_to_backup"


if [ $? -eq 0 ]; then
    echo "Backup completed successfully."
else
    echo "Error: Backup failed."
    exit 1
fi