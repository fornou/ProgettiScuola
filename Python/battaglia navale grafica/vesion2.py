import customtkinter as tk
from random import randint

trovato, cont, cont2, i = False, 0, 1, 0
riga, colonna = randint(0, 4), randint(0, 4)
buttons = []  # Memorizza i bottoni in una lista bidimensionale
pos_casuali = []
m = [
    ['A1', 'A2', 'A3', 'A4', 'A5'],
    ['B1', 'B2', 'B3', 'B4', 'B5'],
    ['C1', 'C2', 'C3', 'C4', 'C5'],
    ['D1', 'D2', 'D3', 'D4', 'D5'],
    ['E1', 'E2', 'E3', 'E4', 'E5']
]
pos_casuale = m[riga][colonna]


posNave = {
    0: "verticale",
    1: "orizzontale"
}

def posizione_nave():

    rand = randint(0,1)
    
    if(rand==0):
        #print("la nave è in posizione verticale")
        if(riga==4):
            pos_casuali.append(m[riga-2][colonna])
            pos_casuali.append(m[riga-1][colonna])
            pos_casuali.append(pos_casuale)
    
        elif(riga==0):

            pos_casuali.append(pos_casuale)
            pos_casuali.append(m[riga+1][colonna])
            pos_casuali.append(m[riga+2][colonna])
           
        else:
            pos_casuali.append(m[riga-1][colonna])
            pos_casuali.append(pos_casuale)
            pos_casuali.append( m[riga+1][colonna])
        
    elif(rand == 1):
       #print("la nave è in posizione orizzontale")
        if(colonna==4):
            pos_casuali.append(m[riga][colonna-2])
            pos_casuali.append(m[riga][colonna-1])
            pos_casuali.append(pos_casuale)
    
        elif(colonna==0):
            pos_casuali.append(pos_casuale)
            pos_casuali.append(m[riga][colonna+1])
            pos_casuali.append(m[riga][colonna+2])

        else:
            pos_casuali.append(m[riga][colonna-1])
            pos_casuali.append(pos_casuale)
            pos_casuali.append(m[riga][colonna+1])
           
posizione_nave()

print("Posizioni casuale:", pos_casuali) 

def disabilita_pulsanti():
    for row in range(5):
        for col in range(5):
            buttons[row][col].configure(state=tk.DISABLED)

def verifica(row, col):
    global cont  # Utilizziamo la variabile cont definita all'esterno della funzione
    global cont2

    if buttons[row][col].cget("text") in pos_casuali:
            label.configure(text="Hai trovato la posizione {} corretta! Era {}".format(cont2, pos_casuali[cont2-1]))
            buttons[row][col].configure(bg_color="green")
            finestra.update()  # Aggiorna l'interfaccia grafica dopo il cambio di colore
            print("Posizione {} è stata trovata correttamente! Era {}".format(cont2, pos_casuali[cont2-1]))
            cont2 += 1
            cont += 1

            if(cont2==4):
                disabilita_pulsanti()
                label.configure(text="Hai trovato tutte le posizioni corrette! Erano {}".format( pos_casuali))
            
    else:
            cont += 1  # Incrementa il contatore dei tentativi
            if cont <=10:
                label.configure(text="Numero Tentativi: {}".format(cont))
                buttons[row][col].configure(bg_color="red")  # Cambia il colore del bottone cliccato
            else:
                label.configure(text="Tentativi Terminati,  la soluzione era {}!".format(pos_casuali))
                disabilita_pulsanti()
                buttons[row][col].configure(bg_color="lightgreen")
                buttons[row][col].configure(fg_color="white")


        
finestra = tk.CTk()
finestra.title("Battaglia Navale")

label = tk.CTkLabel(finestra, text="Numero Tentativi: 0")
label.grid(row=5, column=0, columnspan=5)  # Posiziona il Label sotto i bottoni

for i in range(5):
    row_buttons = []  # Memorizza i bottoni in una lista
    for j in range(5):
        button = tk.CTkButton(finestra, text="{} ".format(m[i][j]), width=4, height=2,
                           command= lambda r=i, c=j: verifica(r, c))
        button.grid(row=i, column=j, padx=5, pady=5)
        row_buttons.append(button)  # Inserisce i bottoni in una lista
    buttons.append(row_buttons)  # Carica la lista riga in buttons

finestra.mainloop()
