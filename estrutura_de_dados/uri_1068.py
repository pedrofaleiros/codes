class Pilha():
    def __init__(self):
        self.stack = []

    def push(self, char):
        self.stack.append(char)

    def pop(self):
        if(self.stack != []):
            self.stack.pop()
            return 0
        else:
            return -1

    def empty(self):
        if self.stack == []:
            return 1
        else:
            return 0

n = int(input())

for i in range(n):
    expressao = input()

    aux = 0

    pilha = Pilha()

    for letra in expressao:
        if letra == '(':
            pilha.push(letra)
        elif letra == ')':
            aux = pilha.pop()
            if aux == -1:
                break
    
    if aux == 0 and pilha.empty():
        print('correct')
    else:
        print('incorrect')

    