/**
 * Restituisce una stringa in base al lanCode passato
 *
 * @param {string} lanCode - L'unica stringa.
 * @returns {string} Ritorna stringa in base al lanCode
 */
function helloWorld(lanCode) {
    if(lanCode == "es"){
        return "Hola Mundo"
    }else if(lanCode == "de"){
        return "Hallo Welt"
    }else if(lanCode == "en"){
        return "Hello World"
    }
}


let result = helloWorld("en")
console.log(result)

result = helloWorld("es")
console.log(result)

result = helloWorld("de")
console.log(result)