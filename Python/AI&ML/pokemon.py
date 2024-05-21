import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Carica il file CSV
url = "content/Pokemon.csv"
data = pd.read_csv(url, sep=',', header=0,  encoding="ISO-8859-1", decimal=",")

# Campi scelti
field = ['name', 'total', 'hp', 'attack', 'defense', 'sp_attack', 'sp_defense', 'speed', 'generation']

# Seleziona colonne dichiarate in field'
mask = data[field]

# Specifica il tipo aggregato desiderato
tipo_aggregato_specifico = ['Bulbasaur', 'Ivysaur', 'Arceus']

# Seleziona solo i valori relativi al tipo aggregato specifico
tipo_aggregato_data = mask[mask['name'].isin(tipo_aggregato_specifico)].dropna()

print(tipo_aggregato_data)

# Creazione del DataFrame da dictionary
df = pd.DataFrame(tipo_aggregato_data)

# Plot
ax = df.plot(kind='bar', figsize=(10, 6), width=0.8)
plt.title('Pokemon Battle')
plt.xlabel('Caratteristiche')
plt.ylabel('Valori')
plt.xticks(np.arange(len(tipo_aggregato_specifico)), tipo_aggregato_specifico, rotation=0)
plt.grid(axis='y')
plt.legend(title='Pokemon')

# Aggiungi i valori sopra le barre
for i in ax.patches:
    ax.text(i.get_x() + i.get_width() / 2, i.get_height() + 0.1, i.get_height() , ha='center', va='bottom')

plt.show()

