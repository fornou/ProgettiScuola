import csv

cont = 0

with open('elenco.csv', 'r') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    
    for row in csv_reader:
        cont += 1
        sigla = ''.join(row).lower()
        print(f"{cont}- {row}, https://flagcdn.com/256x192/{sigla}.png")

