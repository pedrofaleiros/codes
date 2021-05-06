#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Fila():
    
    def __init__(self):
        self.query = []

    def insert(self, num):
        self.query.append(num)

    def remove(self):
        if not self.empty():
            return self.query.pop(0)
        else:
            return 0

    def empty(self):
        if self.query == []:
            return 1
        else:
            return 0

    def primeiro(self):
        if not self.empty():
            return self.query[0]
        else:
            return 0

    def mostra(self):
        print(self.query)
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

fila = Fila()

while True:
    print("\n1 - insert\n2 - remove\n3 - mostra\n4 - primeiro\n0 sair")
    opcao = int(input('Opcao: '))

    if opcao == 1:
        num = int(input('numero: '))
        fila.insert(num)
    elif opcao == 2:
        num = fila.remove()
        if num:
            print(f'\nremovido: {num}')
        else:
            print('\nfila vazia')
    elif opcao == 3:
        fila.mostra()
    elif opcao == 4:
        num = fila.primeiro()
        if num:
            print(f'\nprimeiro da fila: {num}')
        else:
            print('\nfila vazia')
    elif opcao == 0:
        break
