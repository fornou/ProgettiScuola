let wordLetter = ["m","i","a","o"];
let currentGuessedLetter = ["+","+","+","+"];
let cont = 1;

let guessLetter = function(letter){
    if(cont <= 6 && currentGuessedLetter.join() != wordLetter.join()){
        console.log("Tentativo " + (cont) + " ne mancano " + (6 - cont));
        if(wordLetter.includes(letter)){
            //currentGuessedLetter.splice(wordLetter.indexOf(letter), wordLetter.indexOf(letter),letter);
            for(let i = 0; i < wordLetter.length; i++){
                if(wordLetter[i] === letter){
                    currentGuessedLetter[i] = letter;
                }
            }
            console.log("Lettera indovinata "+letter +" in "+currentGuessedLetter.join(""));
        }else{
            console.log(letter +" non è la lettera corretta");
        }
        if(currentGuessedLetter.join() == wordLetter.join("")){
            console.log("Fine Gioco");
            console.log("Hai vinto!!!!");
        }
    }else{
        console.log("Fine Gioco");
        console.log("Hai perso!!!!\nLa parola era " + wordLetter.join(""));
    }
    cont++;

    
}

guessLetter("p");//1
guessLetter("p");//2
guessLetter("p");//3
guessLetter("p");//4
guessLetter("m");//5
guessLetter("o");//6
guessLetter("a");//7
guessLetter("i");//8