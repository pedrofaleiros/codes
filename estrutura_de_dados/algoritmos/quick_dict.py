def quicksort(pessoas, inicio, final):

    if inicio >= final:
        return

    i = inicio
    pivo = pessoas[i]['preco']
    j = final

    while j != i:
        if i > j:
            if pessoas[j]['preco'] > pivo:
                aux = pessoas[i]['nome']
                pessoas[i]['nome'] = pessoas[j]['nome']
                pessoas[j]['nome'] = aux

                aux = pessoas[i]['preco']
                pessoas[i]['preco'] = pessoas[j]['preco']
                pessoas[j]['preco'] = aux

                aux = pessoas[i]['materia']
                pessoas[i]['materia'] = pessoas[j]['materia']
                pessoas[j]['materia'] = aux

                i, j = j, i

        else:
            if pessoas[j]['preco'] < pivo:
                aux = pessoas[i]['nome']
                pessoas[i]['nome'] = pessoas[j]['nome']
                pessoas[j]['nome'] = aux

                aux = pessoas[i]['preco']
                pessoas[i]['preco'] = pessoas[j]['preco']
                pessoas[j]['preco'] = aux

                aux = pessoas[i]['materia']
                pessoas[i]['materia'] = pessoas[j]['materia']
                pessoas[j]['materia'] = aux

                i, j = j, i

        if i > j:
            j += 1
        else:
            j -= 1
    
    quicksort(pessoas, inicio, i-1)
    quicksort(pessoas, i+1, final)

pessoas = []

for i in range(5):
    nome = input('nome: ')
    materia = input('materia: ')
    preco = float(input('preco: '))
    pessoas.append({'nome': nome, 'preco':preco, 'materia':materia})

for pessoa in pessoas:
    print(pessoa)

quicksort(pessoas, 0, len(pessoas)-1)

print("ordenado:")
for pessoa in pessoas:
    print(pessoa)