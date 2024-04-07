import tkinter as tk
from random import randint

colonna, riga, trovato, cont = randint(0, 4), randint(0, 4), False, 0
buttons = []  # Memorizza i bottoni in una lista bidimensionale
m = [
    ['A1', 'A2', 'A3', 'A4', 'A5'],
    ['B1', 'B2', 'B3', 'B4', 'B5'],
    ['C1', 'C2', 'C3', 'C4', 'C5'],
    ['D1', 'D2', 'D3', 'D4', 'D5'],
    ['E1', 'E2', 'E3', 'E4', 'E5']
]

pos_casuale = m[riga][colonna]
print("Posizione casuale:", pos_casuale) 

def disabilita_pulsanti():
    for row in range(5):
        for col in range(5):
            buttons[row][col].configure(state=tk.DISABLED)

def verifica(row, col):
    global cont  # Utilizziamo la variabile cont definita all'esterno della funzione

    if buttons[row][col]['text'].strip() == pos_casuale.strip():
        label.config(text="Hai trovato la posizione corretta!")
        buttons[row][col].configure(bg="green")
        finestra.update()  # Aggiorna l'interfaccia grafica dopo il cambio di colore
        print("La posizione è stata trovata correttamente!")
    else:
        cont += 1  # Incrementa il contatore dei tentativi
        if cont <=10:
            label.config(text="Numero Tentativi: {}".format(cont))
            buttons[row][col].configure(bg="red")  # Cambia il colore del bottone cliccato
        else:
            label.config(text="Tentativi Terminati!")
            disabilita_pulsanti()

finestra = tk.Tk()
finestra.title("Battaglia Navale")

label = tk.Label(finestra, text="Numero Tentativi: 0")
label.grid(row=5, column=0, columnspan=5)  # Posiziona il Label sotto i bottoni

for i in range(5):
    row_buttons = []  # Memorizza i bottoni in una lista
    for j in range(5):
        button = tk.Button(finestra, text="{} ".format(m[i][j]), width=4, height=2,
                           command= lambda r=i, c=j: verifica(r, c))
        button.grid(row=i, column=j, padx=5, pady=5)
        row_buttons.append(button)  # Inserisce i bottoni in una lista
    buttons.append(row_buttons)  # Carica la lista riga in buttons

finestra.mainloop()