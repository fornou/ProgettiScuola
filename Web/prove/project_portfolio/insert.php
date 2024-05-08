<style>
     body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        a{
            text-decoration: none;
            color: white;
        }
        #true{
            background-color: green;
            color: white;
        }
        #false{
            background-color: red;
            color: white;
        }
        button{
            margin-top: 20px;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
</style>
<?php
try {
    // Percorso del file del database SQLite
    $dbFile = 'db.sqlite';
    
    // Connessione al database SQLite
    $db = new PDO('sqlite:' . $dbFile);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $queryCreateTable = "CREATE TABLE IF NOT EXISTS film (
        id INTEGER PRIMARY KEY,
        titolo TEXT,
        anno INTEGER,
        rating REAL
    )";
    
    // Esecuzione della query di creazione della tabella
    $db->exec($queryCreateTable);

    // Recupera i dati dal form
    $titolo = $_POST['titolo'];
    $anno = $_POST['anno'];
    $rating = $_POST['rating'];

    // Query di inserimento con parametri
    $query = "INSERT INTO film (titolo, anno, rating) 
              VALUES (?, ?, ?)";
    $stmt = $db->prepare($query);

    // Bind dei parametri
    $stmt->bindParam(1, $titolo);
    $stmt->bindParam(2, $anno);
    $stmt->bindParam(3, $rating);

    // Esecuzione della query
    $stmt->execute();


    echo "<button id = true><a href=index.html>Inserimento effettuato con successo.</a></button>";
    header("Refresh: 3;url= index.html");

    // Chiusura della connessione
    $db = null;

} catch (PDOException $e) {
    // Gestione degli errori
    die("<button id = false><a href=form.html>Errore durante l'inserimento dei dati</a></button>");
    header("Refresh: 4;url= index.html");
}
?>
