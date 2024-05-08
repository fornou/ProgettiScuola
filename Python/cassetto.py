import pycdio

def open_cd_drive():
    try:
        with pycdio.CdIo() as cdio:
            cdio.eject_tray()
        print("Cassetto del CD aperto.")
    except Exception as e:
        print("Errore durante l'apertura del cassetto del CD:", e)

if __name__ == "__main__":
    open_cd_drive()
56