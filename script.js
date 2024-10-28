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

