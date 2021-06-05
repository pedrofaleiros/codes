def quicksort(pessoas, inicio, final):

    if inicio >= final:
        return

    i = inicio
    pivo = pessoas[i].nome
    j = final

    while j != i:
        if i > j:
            if pessoas[j].nome > pivo:
                pessoas[i], pessoas[j] = pessoas[j], pessoas[i]

                i, j = j, i

        else:
            if pessoas[j].nome < pivo:
                pessoas[i], pessoas[j] = pessoas[j], pessoas[i]

                i, j = j, i

        if i > j:
            j += 1
        else:
            j -= 1
    
    quicksort(pessoas, inicio, i-1)
    quicksort(pessoas, i+1, final)


class Pessoa:
    def __init__(self, nome, preco, materia):
        self.nome = nome
        self.preco = preco
        self.materia = materia


pessoas = []
dados = []

for i in range(5, 0, -1):
    dados.append({
        'nome':f'nome{i}',
        'preco':(i)*3,
        'materia':f'materia{i}'
    })

for dado in dados:
    pessoas.append(Pessoa(dado['nome'], dado['preco'], dado['materia'] ))
    print(dado)
print('-'*20)

for p in pessoas:
    print(f'{p.nome} {p.preco} {p.materia}')
print('-'*20)

quicksort(pessoas, 0, len(pessoas)-1)

for p in pessoas:
    print(f'{p.nome} {p.preco} {p.materia}')
print('-'*20)

dados = []

for p in pessoas:
    dados.append({
        'nome':p.nome,
        'preco':p.preco,
        'materia':p.materia
    })

for dado in dados:
    print(dado)