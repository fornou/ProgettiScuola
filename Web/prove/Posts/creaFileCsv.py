import csv

with open('elenco.csv', 'r') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    
    for row in csv_reader:
        
        # Costruisci e stampa l'URL
        print(f"{row}, https://raw.githubusercontent.com/maboglia/country-flags/ba2cf4101bf029d2ada26da2f95121de74581a4d/svg/{row}.svg")
