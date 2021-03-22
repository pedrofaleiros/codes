from random import randint

fl = open('in', 'w')

for i in range(10000):
    num = randint(1000, 99999)
    fl.write(f'{num}\n');

fl.write('0')

fl.close()
