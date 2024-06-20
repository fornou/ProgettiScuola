/**
 * Restituisce il numero più grande di due valori.
 *
 * @param {number} number1 - Primo valore.
 * @param {number} number2 - Secondo valore.
 * @returns {number} `number1`o `number2` in base al più grande
 */
function greaterNumber(number1, number2) {
    if(number1 > number2){
        return number1
    }else{
        return number2
    }
}


let a = 5
let b = 2
let result = greaterNumber(a, b)

console.log("The greater number of " +a+ " and " +b+ " is " +result+ ".")

a = 1
b = 2
result = greaterNumber(a, b)

console.log("The greater number of " +a+ " and " +b+ " is " +result+ ".")