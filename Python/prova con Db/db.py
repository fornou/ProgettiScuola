import sqlite3

# Connessione al database
conn = sqlite3.connect('../provaConDb/esempio.db')
print(conn.total_changes)
cursor = conn.cursor()

# Creazione della tabella (se non esiste)
cursor.execute('''
    CREATE TABLE IF NOT EXISTS eventi (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome TEXT,
        data DATE
    )
''')

# Input della data da tastiera
data_inserita = input("Inserisci la data dell'evento -> 'YYYY-MM-DD': ")
nome = input("Inserisci il nome dell'evento': ")

# Esempio di dati da inserire
evento = ('Compleanno', data_inserita)

# Inserimento dei dati nella tabella
cursor.execute('INSERT INTO eventi (nome, data) VALUES (?, ?)', evento)

cursor.execute("SELECT * FROM eventi")
rows = cursor.fetchall()

for row in rows:
    print(row)

# Commit delle modifiche e chiusura della connessione
conn.commit()
conn.close()
