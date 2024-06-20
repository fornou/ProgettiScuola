/**
 * Stampa la stringa passata al contrario.
 *
 * @param {string} string - L'unica stringa.
 * @returns {console} La stampa di `string` in reverse.
 */
let printReverse = function(string){
    console.log(string.split("").reverse().join(""))
}

printReverse("Ciao miao bau")
