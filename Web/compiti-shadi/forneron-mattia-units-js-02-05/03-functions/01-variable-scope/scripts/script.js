//Global let
let globalResult;

//Start Functions
function addNumbers(num1, num2) {
    globalResult = num1 + num2;
    console.log("The global result is: " + globalResult);
}

function addNumbers2(num1, num2) {
    let localResult = num1 + num2;
    console.log("The local result is: " + localResult);
}
//End Function

console.log("A variable with global scope")
addNumbers(5, 7);
console.log(globalResult);
/*
    The result in console-browser:
    A variable with global scope
    The global result is: 12
    12
*/

console.log("A variable with local scope")
addNumbers2(5, 7);
console.log(localResult);

/*  
    The result in console-browser:
    A variable with local scope
    The local result is: 12
    
    The console.log() dont print nothing
    its a variable with local scope and
    it declared only in the function
*/