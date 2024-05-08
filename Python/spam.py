import pyautogui as p
import time
from pynput import mouse

code_executed = False

def start_typing():
    global code_executed
    if not code_executed:
        with open("testo.txt", "r") as file:
            p.typewrite(file.read())
        code_executed = True

def on_click(x, y, button, pressed):
    if pressed:
        start_typing()

# Avvia il listener del mouse
with mouse.Listener(on_click=on_click) as listener:
    listener.join()

# Attendere un po' per consentire il tempo di inizializzazione del listener del mouse
time.sleep(3)