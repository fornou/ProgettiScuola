from random  import randint 
from colorama import Fore, Style
import os

m = [
        ['A1','A2','A3','A4','A5'],
        ['B1','B2','B3','B4','B5'],
        ['C1','C2','C3','C4','C5'],
        ['D1','D2','D3','D4','D5'],
        ['E1','E2','E3','E4','E5']
    ]
   
def stampa_tabella():

    for i in range(5):
        print("")
        for j in range(5):
            print("{} ".format(m[i][j]), end="")
    print("\n")

#def sovrascrivi_tabella(a, b):

    #for i in range(5):
        #print("")
        #for j in range(5):
            #if m[i][j]==m[a][b]:
                #print("{} ".format(m[i][j]), end="")

def indovina_numero():

    colonna, riga, trovato, i = randint(0,4), randint(0, 4), False, 0
    pos_scelte = [] 
    pos_casuale = m[riga][colonna]

    print("La posizione casuale è {}".format(pos_casuale))

    
    
    while i<10 and trovato==False:
        
        i+=1
        trattino_alto = "\u2015"*11
        print("___________\n"
              "Tentativo {}\n{}".format(i, trattino_alto))
        
        stampa_tabella()

        a = input("Prova a indovinare riga--> A, B, C, D, E\n").upper()
        b = int(input("Prova a indovinare colonna--> 1, 2, 3, 4, 5\n"))

        i-=1

        a = ord(a) - 65
        b -=1

        pos_scelta = m[a][b] #momentanea
        pos_scelte.append(pos_scelta) #vettore

        os.system('cls')

        if i>=1:
            print("Le posizioni scelte sono:")
            for j in range(len(pos_scelte)):
                print("- {}".format(pos_scelte[j]))
        else:
            print("La posizione scelta è {}".format(pos_scelte[0]))

        if pos_casuale==pos_scelta:
            
            print("La soluzione è {}\nBravo hai indovinato dopo {} possibilità".format(pos_scelta, i))
            trovato = True
            m[a][b] = f"{Fore.GREEN}{'SI'}{Style.RESET_ALL}"
            stampa_tabella()

        else:
            
            if a>riga:
                print("valore riga troppo grande")

            elif a<riga:
                print("valore riga troppo piccola")

            elif a==riga:
                print("valore riga giusto")

            if b>colonna:
                print("valore colonna troppo grande")
            
            elif b==colonna:
                print("valore colonna giusto")

            elif b<colonna:
                print("valore colonna troppo piccola")
        
        i+=1

        m[a][b] = f"{Fore.RED}{'NO'}{Style.RESET_ALL}"

    if trovato==False:
        print("non hai indovinato la casella era {}".format(pos_casuale))

indovina_numero()
