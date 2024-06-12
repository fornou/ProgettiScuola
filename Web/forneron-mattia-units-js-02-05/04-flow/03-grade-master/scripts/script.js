/**
 * Restituisce un carattere in base al numberScore passato
 *
 * @param {number} numberScore- L'unica numero.
 * @returns {string} Ritorna stringa in base al numberScore
 */
function assignGrade(numberScore) {
    if(numberScore == 10){
        return "A"
    }else if(numberScore == 9){
        return "B"
    }else if(numberScore == 8){
        return "C"
    }else if(numberScore == 7){
        return "D"
    }else if(numberScore == 6){
        return "E"
    }else if(numberScore == 5){
        return "F"
    }else{
        return "Not assigned"
    }
}


let result = assignGrade(10)
console.log(result)

result = assignGrade(5)
console.log(result)

result = assignGrade(2)
console.log(result)