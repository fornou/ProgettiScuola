let cartForParty = {
    banana: "1.25",
    handkerchief: ".99",
    Tshirt: "25.01",
    apple: "0.60",
    nalgene: "10.34",
    proteinShake: "22.36"
};
let sum = 0

Object.
    values(cartForParty).
    forEach(value => {
        sum = sum + Number(value)
})

console.log("Somma:"+ sum + "\nMedia: " + Math.round(sum/( Object.values(cartForParty).length)*100)/100)