/**
 * Stampa la stringa passata al contrario.
 *
 * @param {string} string - L'unica stringa.
 * @returns {string} `string` in reverse.
 */
let printReverse = function(string){
    return string.split("").reverse().join(""); 
}


console.log(printReverse("Ciao mondo"))