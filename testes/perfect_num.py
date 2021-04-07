def is_perfect(num):
    
    if num % 2 == 1:
        return 0

    lista = []

    for i in range(1, num):
        if num % i == 0:
            lista.append(i)

    soma = 0

    for n in lista:
        soma += n

    if soma == num:
        return 1
    else:
        return 0

def factorial(num):
    if num == 1:
        return 1
    else:
        return factorial(num-1) * num

num = int(input('num> '))
print(factorial(num))
