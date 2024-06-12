/**
 * Capitalizza la prima lettera della stringa.
 *
 * @param {string} string - L'unica stringa.
 * @returns {string} `string` con prima lettera capitalizzata.
 */
let capital = function(string){
    return string[0].toUpperCase() + string.slice(1);
}
/**
 * Capitalizza le prime lettere delle parole della stringa.
 *
 * @param {string} string - L'unica stringa.
 * @returns {string} `string` con  prime lettere delle parole della stringa capitalizzate.
 */
let capital2 = function(string){
    return string.split(" ").map(word => capital(word)).join(" ");
}

let hello = "ciao mondo sono felice oggi"

console.log(capital(hello));

console.log(capital2(hello));

