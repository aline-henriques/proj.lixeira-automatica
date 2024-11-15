document.addEventListener("DOMContentLoaded", function () {
    const sections = document.querySelectorAll(".fade-in");

    function checkVisibility() {
        sections.forEach(section => {
            const rect = section.getBoundingClientRect();
            if (rect.top < window.innerHeight && rect.bottom > 0) {
                section.classList.add("visible");
            }
        });
    }

    window.addEventListener("scroll", checkVisibility);
    checkVisibility(); 
});

function updateProgressBar() {
    const documentHeight = document.documentElement.scrollHeight - document.documentElement.clientHeight;
    const scrollPosition = window.scrollY;
    const scrollProgress = (scrollPosition / documentHeight) * 100;
    const progressBar = document.getElementById('progress-bar');
    progressBar.style.width = scrollProgress + '%';
}

window.onscroll = function() {
    updateProgressBar();
};
