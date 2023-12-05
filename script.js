document.addEventListener("DOMContentLoaded", function(){
    const container = document.getElementById("container");
    const noBtn = document.getElementById("noBtn");
    
    noBtn.addEventListener("mouseover", function() {
      container.classList.remove("centered");
      const x = Math.floor(Math.random() * (window.innerWidth - container.offsetWidth));
      const y = Math.floor(Math.random() * (window.innerHeight - container.offsetHeight));
      container.style.left = `${x}px`;
      container.style.top = `${y}px`;
    });
    
    noBtn.addEventListener("click", function() {
      container.classList.remove("centered");
      const x = Math.floor(Math.random() * (window.innerWidth - container.offsetWidth));
      const y = Math.floor(Math.random() * (window.innerHeight - container.offsetHeight));
      container.style.left = `${x}px`;
      container.style.top = `${y}px`;
    });
  });
  
  const yesBtn = document.getElementById("yesBtn");
  
  yesBtn.addEventListener("click", function() {
    alert("hehehe");
  });
  