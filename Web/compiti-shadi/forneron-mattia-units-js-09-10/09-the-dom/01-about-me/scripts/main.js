document.body.style.fontFamily = ("Arial, sans-serif")

document.getElementById('nickname').textContent = "Mattia Forneron"

document.getElementById('favorites').textContent = "Sports, Film, Music"

document.getElementById('hometown').textContent = "San Secondo di Pinerolo"

let lista = document.getElementsByTagName('ul')

let li = document.querySelectorAll("li")

li.forEach(e=> {
    e.classList.add("list-item")
});

let myImg = document.createElement("img")

myImg.src = "https://www.repstatic.it/content/contenthub/img/2020/09/16/002100106--0b81d77e-19e5-4ad8-a357-30331cd709c9.jpg"

document.body.appendChild(myImg)

setTimeout(()=>{

    let link = document.createElement("link");
    link.rel = "stylesheet";
    link.href = "styles/style.css";
    document.head.appendChild(link);

},4000)
