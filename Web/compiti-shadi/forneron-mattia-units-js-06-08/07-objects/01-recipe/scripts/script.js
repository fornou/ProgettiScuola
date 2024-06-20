let objs = [
    {
        "titolo": "Titolo1",
        "servings": 10,
        "ingredients":{
            "ing1": "ingrediente1",
            "ing2": "ingrediente2",
            "ing3": "ingrediente3"
        }
    },
    {
        "titolo": "Titolo2",
        "servings": 20,
        "ingredients":{
            "ing1": "ingrediente1",
            "ing2": "ingrediente2",
            "ing3": "ingrediente3"
        }
    }
]

objs.forEach(obj=> {
    console.log(obj.titolo)
    console.log(obj.servings)
    console.log(obj.ingredients)
});