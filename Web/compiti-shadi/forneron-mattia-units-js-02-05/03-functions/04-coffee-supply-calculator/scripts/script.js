//Constant
const maxAge = 100

//Start Functions
function calculateSupply(age, amountPerDay) {
    console.log("You will need "+ (amountPerDay * (365*(maxAge - age))).toFixed()+" liters of coffee to last you until the ripe old age of "+ maxAge)
}
//End Function

calculateSupply(19, 0.3);
calculateSupply(60, 0.6);
calculateSupply(98, 0.1);

/*
    The result in console-browser:
    You will need 8869.5 liters of coffee to last you until the ripe old age of 100
    You will need 8760 liters of coffee to last you until the ripe old age of 100
    You will need 73 liters of coffee to last you until the ripe old age of 100
*/