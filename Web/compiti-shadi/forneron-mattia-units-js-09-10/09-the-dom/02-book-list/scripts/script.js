let books = [
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    },
    {
        title: 'The Design of EveryDay Things',
        author: 'Don Norman',
        alreadyRead: false,
        img: 'https://picsum.photos/200/300'
    }, 
    {
        title: 'The Most Human Human',
        author: 'Brian Christian',
        alreadyRead: true,
        img: 'https://picsum.photos/200/300'
    }
];

books.forEach(book => {
    let ul = document.createElement("ul")
    let img = document.createElement("img")
    let title = document.createElement("li")
    let author = document.createElement("li")
    let letto = document.createElement("li")
    let body = document.body;

    img.src = book.img
    title.textContent = book.title
    author.textContent= book.author

    setTimeout(()=>{

        let link = document.createElement("link");
        link.rel = "stylesheet";
        link.href = "styles/style.css";
        document.head.appendChild(link);

        if(book.alreadyRead){
            letto.textContent="Letto"
            letto.classList.add("letto")
        }else{
            letto.textContent="Da Leggere"
            letto.classList.add("daLeggere")
        }

        ul.appendChild(letto)
    
    },5000)

    
    
    ul.appendChild(img)
    ul.appendChild(title)
    ul.appendChild(author)
    
    
    body.appendChild(ul)
    
});






   