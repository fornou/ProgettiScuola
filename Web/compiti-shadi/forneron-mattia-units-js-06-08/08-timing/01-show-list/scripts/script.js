const items = [
    "Apple",         
    "Banana",        
    "Orange",
    "Strawberry"              
];

let i = 0

function displayItemTimeOut(){
    setTimeout(()=>{
        const cont = document.getElementById("container");

        if(i<items.length){
            const p = document.createElement("p")
            p.textContent = items[i];
            cont.appendChild(p);
            i++;
        }else{
            i = 0;
            cont.innerHTML = ""
        }
        displayItemTimeOut()
    }, 1000); 
}

//displayItemTimeOut();


function displayItemInterval(time){
    let one = setInterval(() => {
        const cont = document.getElementById("container");
    
        if(i<items.length){
            const p = document.createElement("p")
            p.textContent = items[i]
            cont.appendChild(p)
            i++;
        }else{
            i = 0;
            cont.innerHTML="";
            clearInterval(one);
            displayItemInterval(500);
        }
    }, time);
}

displayItemInterval(500)