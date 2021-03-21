from random import randint

fl = open('in', 'w')

for i in range(10000):
    num = randint(1, 1000)
    fl.write(f'{num}\n');

fl.write('0')

fl.close()
