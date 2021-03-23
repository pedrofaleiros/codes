class Pilha():

    def __init__(self):
        self.stack = []

    def push(self, num):
        self.stack.append(num)

    def pop(self):
        if not self.empty():
            return self.stack.pop()
        else:
            return 0

    def mostra(self):
        if not self.empty():
            print(self.stack)
        else:
            print('pilha vazia')

    def empty(self):
        if self.stack == []:
            return 1
        else:
            return 0

pilha = Pilha()

while True:
    print("1 - push\n2 - pop\n3 - mostra\n0 sair")
    opcao = int(input('Opcao: '))

    if opcao == 1:
        num = int(input("num: "))
        pilha.push(num)
    elif opcao == 2:
        num = pilha.pop()
        if num != 0:
            print(f'removido: {num}')
        else:
            print('pilha vazia')
    elif opcao == 3:
        pilha.mostra()
    elif opcao == 0:
        break