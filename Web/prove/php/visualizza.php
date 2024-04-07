<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizzazione dati da tabella SQLite</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }
        table, th, td {
            border: 1px solid black;
            padding: 8px;
        }
    </style>
</head>
<body>
    <h1>Dati dalla tabella SQLite</h1>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Nome</th>
                <th>Cognome</th>
                <th>Età</th>
            </tr>
        </thead>
        <tbody>
            <?php
            try {
                // Connessione al database SQLite
                $dbFile = 'db.sqlite';
                $db = new PDO('sqlite:' . $dbFile);
                $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Query per selezionare i dati dalla tabella
                $querySelect = "SELECT * FROM persone";
                $stmt = $db->query($querySelect);
                
                // Stampare i dati all'interno della tabella
                while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                    echo "<tr>";
                    echo "<td>" . $row['id'] . "</td>";
                    echo "<td>" . $row['nome'] . "</td>";
                    echo "<td>" . $row['cognome'] . "</td>";
                    echo "<td>" . $row['eta'] . "</td>";
                    echo "</tr>";
                }

                // Chiusura della connessione
                $db = null;
            } catch (PDOException $e) {
                // Gestione degli errori
                die("Errore durante il recupero dei dati: " . $e->getMessage());
            }
            ?>
        </tbody>
    </table>
</body>
</html>
