from selenium import webdriver
from bs4 import BeautifulSoup
import pyautogui as p
import time
import datetime

tempo_iniziale = datetime.datetime.now()
tempo_attuale = datetime.datetime.now()
driver = webdriver.Chrome()
cont = 0
url = 'https://10fastfingers.com/typing-test/italian'
driver.get(url)

html = driver.page_source

soup = BeautifulSoup(html, 'html.parser')

span_with_wordnr = soup.find_all('span', {'wordnr': True})

time.sleep(5)

for text in span_with_wordnr:
    cont+=1
    print(f"{cont}  --> {text.text}")
    p.write(text.text)
    p.write(" ")
    time.sleep(0.4)
    if cont >= 150 or (tempo_attuale - tempo_iniziale).total_seconds() > 60: 
        break
    tempo_attuale = datetime.datetime.now()

    

input("Vuoi uscire dal sito")
driver.quit()
