let objs = [
    {
        titolo: "Titolo1",
        servings: 10,
        ingredients:[
            "ingrediente1",
            "ingrediente2",
            "ingrediente3"
        ]
    },
    {
        titolo: "Titolo2",
        servings: 20,
        ingredients:[
            "ingrediente1",
            "ingrediente2",
            "ingrediente3"
        ]
    }
]

objs.forEach(obj=> {
    console.log(obj.titolo)
    console.log(obj.servings)
    obj.ingredients.forEach(ingredient=>{
        console.log(ingredient)
    })
});