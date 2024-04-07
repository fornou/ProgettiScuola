import json

continua = "s"

while(continua=="s"):
    nome = input("Inserisci il nome: ")
    cognome = input("Inserisci il cognome: ")
    anno = int(input("Inserisci anno di nascita: "))
    nazion = input("Inserisci la nazionalità: ")
    etnia = input("Inserisci l'etnia: ")
    occhi = input("Inserisci colore occhi: ")
    capelli = input("Inserisci colore capelli: ")

    dati = {
    "nome": nome,
    "cognome": cognome,
    "anno": anno,
    "nazion": nazion,
    "etnia": etnia,
    "occhi": occhi,
    "capelli": capelli
    }


    with open("insertInJson/dati_utente.json", 'w') as file_json:
        json.dump(dati, file_json)

    print("I dati sono stati inseriti nel file JSON!")

    continua = input("continua:(s/n)")