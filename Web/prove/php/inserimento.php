<?php
try {
    // Percorso del file del database SQLite
    $dbFile = 'db.sqlite';
    
    // Connessione al database SQLite
    $db = new PDO('sqlite:' . $dbFile);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $queryCreateTable = "CREATE TABLE IF NOT EXISTS persone (
        id INTEGER PRIMARY KEY,
        nome TEXT,
        cognome TEXT,
        eta INTEGER
    )";
    
    // Esecuzione della query di creazione della tabella
    $db->exec($queryCreateTable);

    // Recupera i dati dal form
    $nome = $_POST['nome'];
    $cognome = $_POST['cognome'];
    $eta = $_POST['eta'];

    // Query di inserimento con parametri
    $query = "INSERT INTO persone (nome, cognome, eta) VALUES (:nome, :cognome, :eta)";
    $stmt = $db->prepare($query);

    // Associazione dei parametri
    $stmt->bindParam(':nome', $nome);
    $stmt->bindParam(':cognome', $cognome);
    $stmt->bindParam(':eta', $eta);

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
