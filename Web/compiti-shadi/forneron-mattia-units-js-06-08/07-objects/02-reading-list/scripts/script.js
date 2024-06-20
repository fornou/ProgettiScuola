// Creating an array of book objects
let books = [
    {
        title: "The Hobbit",
        author: "J.R.R. Tolkien",
        alreadyRead: true
    },
    {
        title: "The Lord of the Rings",
        author: "J.R.R. Tolkien",
        alreadyRead: false
    },
    {
        title: "1984",
        author: "George Orwell",
        alreadyRead: true
    },
    {
        title: "To Kill a Mockingbird",
        author: "Harper Lee",
        alreadyRead: false
    }
];

books.forEach(book => {
    console.log(`${book.title} by ${book.author}`);
    if (book.alreadyRead) {
        console.log(`You already read "${book.title}" by ${book.author}`);
    } else {
        console.log(`You still need to read "${book.title}" by ${book.author}`);
    }
});
