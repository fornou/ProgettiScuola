function changeImage() {
    var valore = Math.floor(Math.random() * 3) + 1; // Genera un numero intero tra 1 e 3
    var src;

    switch (valore) {
        case 1:
            src = 'img/sasso.png';
            break;
        case 2:
            src = 'img/carta.png';
            break;
        case 3:
            src = 'img/forbice.png';
            break;
    }

    var img = document.getElementById("elemento"); // Corretto: getElementById, non getElementsByTagId
    img.src = src;
}
