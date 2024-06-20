<?php
try {
    // Percorso del file del database SQLite
    $dbFile = 'db.sqlite';
    
    // Connessione al database SQLite
    $db = new PDO('sqlite:' . $dbFile);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $queryCreateTable = "CREATE TABLE IF NOT EXISTS candidati (
        id INTEGER PRIMARY KEY,
        nome TEXT,
        nome2 TEXT,
        cognome TEXT,
        peso INTEGER,
        eta INTEGER,
        gender TEXT,
        h_color TEXT,
        e_color TEXT,
        email TEXT,
        phone TEXT,
        addr TEXT,
        mission TEXT,
        descr TEXT
    )";
    
    // Esecuzione della query di creazione della tabella
    $db->exec($queryCreateTable);

    // Recupera i dati dal form
    $nome = $_POST['first'];
    $nome2 = $_POST['second'];
    $cognome = $_POST['last'];
    $weight = $_POST['weight'];
    $age = $_POST['age'];
    $gender = $_POST['gender'];
    $col_h = $_POST['color-hair'];
    $col_e = $_POST['color-eye'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $addr = $_POST['address'];
    $mission = $_POST['mission'];
    $descr = $_POST['descr'];

    // Query di inserimento con parametri
    $query = "INSERT INTO candidati (nome, nome2, cognome, peso, eta, gender, h_color, e_color, email, phone, addr, mission, descr) 
              VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    $stmt = $db->prepare($query);

    // Bind dei parametri
    $stmt->bindParam(1, $nome);
    $stmt->bindParam(2, $nome2);
    $stmt->bindParam(3, $cognome);
    $stmt->bindParam(4, $weight);
    $stmt->bindParam(5, $age);
    $stmt->bindParam(6, $gender);
    $stmt->bindParam(7, $col_h);
    $stmt->bindParam(8, $col_e);
    $stmt->bindParam(9, $email);
    $stmt->bindParam(10, $phone);
    $stmt->bindParam(11, $addr);
    $stmt->bindParam(12, $mission);
    $stmt->bindParam(13, $descr);

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
