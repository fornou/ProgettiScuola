<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Modulo Utenze</title>
</head>
<style>

    table{
        border-collapse: collapse;
        margin: 0 auto;
    }
    td{
        border: 1px solid black;
    }

    .cont{
        margin: 0 auto;
        border: 1px solid black;
        text-align: center;
        margin:30px;
    }
    p{
        text-align: center;
    }
    form{
        padding: 20px;
    }
</style>
<body>
<div class="cont">

<h1>UTENZE</h1>

<form action="utenze.php" method="post" >

   
    Seleziona codice dell'utente:
    <select name="scelta">

    <option value="0"></option>

        <?php

            $conn = new mysqli("localhost","root","","utenze");

            $ris = $conn->query("SELECT Codice FROM utenti") or die("errore");

            $numR = $ris->n_rows;

            foreach($ris as $rows)
            {
                echo"<option value=".$rows['Codice'].">".$rows['Codice']."</option>";
            }

            $conn->close();

        ?>

    </select>
    <input type="submit" name="invia" value="INVIA">
    <input type="submit" name="aggiorna" value="AGGIORNA">

</form>

</div>
<?php


    $conn = new mysqli("localhost","root","","utenze");

    if(isset($_POST["invia"]))
    {
        $scelta = $_POST['scelta'];

        if($scelta==0)
        {
            echo"<p>Fai la tua scelta!!</p>";
        }
        else{

            $query= "SELECT Cognome, Nome, bollette.Data, bollette.Consumo, bollette.Importo FROM utenti INNER JOIN bollette ON bollette.CodUtente = utenti.Codice WHERE Codice='$scelta'";

            $ris = $conn->query($query) or die("Error in visual");

            $numR = $ris->num_rows;

            if($numR=0)
            {
                echo"<table><tr><td>NOME</td><td>COGNOME'</td><td>DATA</td><td>CONSUMO</td><td>IMPORTO</td></tr>";

                foreach($ris as $riga)
                {
                    echo"<tr><td>".$riga['Nome']."</td><td>".$riga['Cognome']."</td><td>".$riga['Data']."</td><td>".$riga['Consumo']."</td><td>".$riga['Importo']."</td></tr>";
                }

                echo"</table>";

                $query2= "SELECT SUM(Importo) FROM bollette INNER JOIN utenti ON bollette.CodUtente = utenti.Codice WHERE Codice='$scelta'";

                $ris2 = $conn->query($query) or die("Error in visual");

                foreach($ris as $riga)
                {
                    echo"<tr><td>".$riga['Nome']."</td><td>".$riga['Cognome']."</td><td>".$riga['Data']."</td><td>".$riga['Consumo']."</td><td>".$riga['Importo']."</td></tr>";
                }

            }
            else{
                echo"<p>Non c'è bolletta con con code $scelta</p>";
            }
           
        }
    }

    $conn->close();
?>
   
</body>
</html>