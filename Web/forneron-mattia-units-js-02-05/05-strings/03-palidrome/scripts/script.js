/**
 * Stampa la stringa passata al contrario.
 *
 * @param {string} string - L'unica stringa.
 * @returns {string} `string` in reverse.
 */
let reverse = function(string){
    return string.split("").reverse().join("")
}
/**
 * Ritorna true se è palindroma la stringa passata.
 *
 * @param {string} string - L'unica stringa.
 * @returns {boolean} Valore vero o falso.
 */
let isPalindrome = function(string){
    if(string == reverse(string)){
        return true;
    }else{
        return false;
    }
}

console.log(isPalindrome("madam e madam"));