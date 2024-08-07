document.addEventListener("DOMContentLoaded", function () {
    const links = document.querySelectorAll("a");
    links.forEach(function (link) {
      link.addEventListener("click", function (event) {
        event.preventDefault();
        const targetPage = link.getAttribute("href");
        document.querySelector(".page-container").classList.add("page-hidden");
        setTimeout(function () {
          window.location.href = targetPage;
        }, 500);
      });
    });
  });
  