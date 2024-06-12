document.addEventListener('DOMContentLoaded', function() {
    const container = document.querySelector('.reel-container');
    const posts = document.querySelectorAll('.instagram-post');

    let currentIndex = 0;

    function scrollToPost(index) {
        posts[index].scrollIntoView({ behavior: 'smooth', block: 'center' });
    }

    container.addEventListener('wheel', function(event) {
        if (event.deltaY > 0) {
            // Scorrimento verso il basso
            if (currentIndex < posts.length - 1) {
                currentIndex++;
                scrollToPost(currentIndex);
            }
        } else {
            // Scorrimento verso l'alto
            if (currentIndex > 0) {
                currentIndex--;
                scrollToPost(currentIndex);
            }
        }
        event.preventDefault();
    });
});
