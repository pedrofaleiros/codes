var num = 1


function clicar(){
    num += 1
    let aux = document.getElementById('clique')
    if(num % 2 == 0){
        aux.innerText = 'Sim'
    }else{
        aux.innerText = 'Nao'
    }
}