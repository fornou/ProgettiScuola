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
              VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    $stmt = $db->prepare($query);

    // Bind dei parametri
    $stmt->bindParam(1, $titolo);
    $stmt->bindParam(2, $anno);
    $stmt->bindParam(3, $rating);

    // Esecuzione della query
    $stmt->execute();

    echo "Inserimento effettuato con successo.";

    // Chiusura della connessione
    $db = null;

} catch (PDOException $e) {
    // Gestione degli errori
    die("Errore durante l'inserimento dei dati: " . $e->getMessage());
}
?>
