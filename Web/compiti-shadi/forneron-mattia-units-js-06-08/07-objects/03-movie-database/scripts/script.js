let movies = [
    {
        title: "Puff the Magic Dragon",
        duration: 30,
        stars: ["Puff", "Jackie", "Living Sneezes"]
    },
    {
        title: "The Lord of the Rings",
        duration: 178,
        stars: ["Elijah Wood", "Ian McKellen", "Viggo Mortensen"]
    },
    {
        title: "Inception",
        duration: 148,
        stars: ["Leonardo DiCaprio", "Joseph Gordon-Levitt", "Ellen Page"]
    }
];

function printMovie(movie) {
    console.log(`${movie.title} lasts for ${movie.duration} minutes. Stars: ${movie.stars.join(', ')}.`);
}

//printMovie(movies.at(0));

movies.forEach(movie => printMovie(movie));
