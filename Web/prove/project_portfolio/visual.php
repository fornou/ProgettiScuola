<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visual Data - MyFilm</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

    <style>
      body {
        position: relative;
        min-height: 100vh;
      }
      nav{
        margin-bottom: 50px;
      }

      footer {
        position: absolute;
        width: 100%;
        height: 100px; 
        background-color: #333;
        color: white;
        text-align: center;
      }
    </style>
  </head>
  <body>
      <!-- Navbar -->
      <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
          <div class="container">
            <a class="navbar-brand" href="#">MyFilm</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
              <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarSupportedContent">
              <ul class="navbar-nav ml-auto">
                <li class="nav-item">
                  <a class="nav-link" href="index.html">Home</a>
                </li>
                <li class="nav-item">
                  <a class="nav-link" href="form.html">Insert</a>
                </li>
                <li class="nav-item">
                  <a class="nav-link active" href="visual.php">Visual</a>
                </li>
              </ul>
            </div>
          </div>
      </nav>

      <!-- Table and Filter-->
      <div class="container">
          <h2>Filterable Table</h2>
          <p>Type something in the input field to search the table for first names, last names or emails:</p>  
          <input class="form-control" id="myInput" type="text" placeholder="Search..">
          <br>
          <table class="table table-bordered table-striped">
              <thead>
                  <tr>
                  <th>Titolo</th>
                  <th>Anno</th>
                  <th>Rating</th>
                  </tr>
              </thead>
              <tbody id="myTable">
              <?php
                  try {
                      // Connessione al database SQLite
                      $dbFile = 'db.sqlite';
                      $db = new PDO('sqlite:' . $dbFile);
                      $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                      // Query per selezionare i dati dalla tabella
                      // $queryD = "DELETE FROM film where id >  50";
                      // $stmt = $db->query($queryD);
                      // $stmt -> execute();

                      // Query per selezionare i dati dalla tabella
                      $querySelect = "SELECT * FROM film";
                      $stmt = $db->query($querySelect);
                      
                      // Stampare i dati all'interno della tabella
                      while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                          echo "<tr>";
                          echo "<td>" . $row['id'] . "</td>";
                          echo "<td>" . $row['titolo'] . "</td>";
                          echo "<td>" . $row['anno'] . "</td>";
                          echo "<td>" . $row['rating'] . "</td>";
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
      </div>

      <!-- Footer -->
      <footer class="my-5 pt-5 bg-dark text-body-secondary text-white text-center py-3">
          <p>&copy; 2024 MyFilm. All rights reserved.</p>
      </footer>

      <!--Script-->
      <script>
         $(document).ready(function(){
            $("#myInput").on("keyup", function() {
                var value = $(this).val().toLowerCase();
                $("#myTable tr").each(function() {
                    var rowText = $(this).text().toLowerCase();
                    if (rowText.indexOf(value) !== -1) {
                        $(this).show();
                    } else {
                        $(this).hide();
                    }
                });
            });
        });
    </script>
  </body>
</html>
