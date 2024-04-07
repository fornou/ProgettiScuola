import time
import pyautogui as p

lettere_special = {
    'q': '+',
    'w': 'x',
    'e': '÷',
    'r': '=',
    't': '/',
    'y': '_',
    'u': '<',
    'i': '>',
    'o': '[',
    'p': ']',
    'a': '!',
    's': '@',
    'd': '#',
    'f': '€',
    'g': '%',
    'h': '^',
    'j': '&',
    'k': '*',
    'l': '(',
    'z': ')',
    'x': '-',
    'c': '\'',
    'v': '"',
    'b': ':',  
    'n': ';',
    'm': ','
}

def cripta(messaggio, dizionario):
    messaggio_sostituito = ''
    for carattere in messaggio:
        carattere_sostituito = dizionario.get(carattere, carattere)
        messaggio_sostituito += carattere_sostituito
    return messaggio_sostituito  

def digitaTesto():
    text = input("Inserisci il tuo messaggio: ")
    text = cripta(text, lettere_special)
    return text

def invia_messaggi():
    text = digitaTesto()
    conferma = input("Scrivo dove hai il ping: ")
    if conferma == "si":
        time.sleep(4)
        p.write(text)
        p.press('enter')
        time.sleep(1)

invia_messaggi()
    



    
