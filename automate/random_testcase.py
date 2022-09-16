import random
gen = lambda l: bin(2**l + random.randrange(2**l))[3:]
numofboxes, blocksize, keysize, rounds, t = int(input("numofboxes: ")), int(input("blocksize: ")), int(input("keysize: ")), int(input("rounds: ")), int(input("t: "))
with open('testcase.txt', 'w') as file:
    file.write(str(numofboxes)+'\n')
    file.write(str(blocksize)+'\n')
    file.write(str(keysize)+'\n')
    file.write(str(rounds)+'\n')
    file.write(gen(keysize)+'\n')
    file.write(str(t)+'\n')
    for i in range(t):
        file.write(gen(blocksize)+'\n')