const items = [
    "Apple",         
    "Banana",        
    "Orange",        
    "Strawberry",    
    "Grapes",        
    "Pasta",         
    "Rice",          
    "Bread",         
    "Milk",          
    "Cheese",        
    "To Kill a Mockingbird",  
    "1984",                   
    "The Great Gatsby",       
    "Moby Dick",              
    "War and Peace",          
    "The Catcher in the Rye", 
    "The Hobbit",             
    "Pride and Prejudice",    
    "Harry Potter",           
    "The Lord of the Rings",  
    "Laptop",                 
    "Smartphone",             
    "Tablet",                 
    "Headphones",             
    "Charger",                
    "Backpack",               
    "Notebook",               
    "Pen",                    
    "Watch",                  
    "Water Bottle"            
];

let i = 0

function displayItemTimeOut(){
    if(i<items.length){
        console.log(items[i])
        i++;
    }else{
        return;
    }
    setTimeout(displayItemTimeOut, 1000); 
}

function displayItemInterval(){
    setInterval(() => {
        const cont = document.getElementById("container");
    
        if(i<items.length){
            console.log(items[i])//debug
            const p = document.createElement("p")
            p.textContent = items[i]
            cont.appendChild(p)
            i++;
        }else{
            return;
        }
    }, 1000);
}


displayItemInterval();





