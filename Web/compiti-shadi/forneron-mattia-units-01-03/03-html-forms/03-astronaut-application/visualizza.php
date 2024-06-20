<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizzazione dati da tabella SQLite</title>
    <link rel="stylesheet" href="styles/style.css">
</head>
<body>
    <h1>Dati Inseriti</h1>
    <table>
        <thead>
            <tr>
            <th>NOME</th>
            <th>NOME2</th>
            <th>COGNOME</th>
            <th>PES</th>
            <th>ETA</th>
            <th>GENDER</th>
            <th>H_COLOR</th>
            <th>E_COLOR</th>
            <th>EMAIL</th>
            <th>PHONE</th>
            <th>ADDR</th>
            <th>MISSION</th>
            <th>DESCR</th>
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
                $querySelect = "SELECT * FROM candidati";
                $stmt = $db->query($querySelect);
                
                // Stampare i dati all'interno della tabella
                while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                    echo "<tr>";
                    echo "<td>" . $row['nome'] . "</td>";
                    echo "<td>" . $row['nome2'] . "</td>";
                    echo "<td>" . $row['cognome'] . "</td>";
                    echo "<td>" . $row['peso'] . "</td>";
                    echo "<td>" . $row['eta'] . "</td>";
                    echo "<td>" . $row['gender'] . "</td>";
                    echo "<td style='background: " . $row['h_color'] . ";'></td>";
                    echo "<td style='background: " . $row['e_color'] . ";'></td>";
                    echo "<td>" . $row['email'] . "</td>";
                    echo "<td>" . $row['phone'] . "</td>";
                    echo "<td>" . $row['addr'] . "</td>";
                    echo "<td>" . $row['mission'] . "</td>";
                    echo "<td>" . $row['descr'] . "</td>";
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
    <br>
    <button><a href="index.html">Back to Form</a></button>
</body>
</html>
