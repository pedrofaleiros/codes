var num = 1

function clicar(){
    carregar()
    num += 1
    let aux = document.getElementById('clique')
    if(num % 2 == 0){
        aux.innerText = 'Sim'
    }else{
        aux.innerText = 'Nao'
    }
}

function carregar(){
    let txt = document.getElementById('hora')
    let date = new Date()
    let hora = date.getHours()
    let min = date.getMinutes()
    let sec = date.getSeconds()
    if(min < 10){
        min = "0"+min
    }
    if(sec < 10){
        sec = "0"+sec
    }
    txt.innerText = `${hora}:${min}:${sec}`
}

setInterval(carregar, 1000)