class Pessoa{

    constructor(nome, idade){
        this._nome = nome;
        this._idade = idade;
    }

    get nome(){
        return this._nome;
    }

    set nome(nome){
        this._nome = nome
    }

    falar(msg){
        console.log(`${this._nome} diz: ${msg}`);
    }

}

const p1 = new Pessoa('Pedro', 19);

p1.falar("Eae carai");

p1.nome = "Faleiros"

p1.falar("Eae carai");

Object.freeze(p1)
