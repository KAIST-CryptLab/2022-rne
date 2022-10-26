from __future__ import print_function # https://stackoverflow.com/questions/11266068/python-avoid-new-line-with-print-command
import time, os

with open('testcase.txt', 'r') as file: # does not read keys
    numofboxes = int(file.readline().strip())
    blocksize = int(file.readline().strip())
    keysize = int(file.readline().strip())
    rounds = int(file.readline().strip())
    file.readline()
    t = int(file.readline().strip())

key_var_end = blocksize * (rounds + 2) * t + keysize

with open('ANF.txt', 'r') as file:
    ANF = file.readlines()

num_guess = int(input('How many bits to guess? '))
assert num_guess <= keysize

start_time = time.time() # comonly used technique
end_time = None

for i in range(2**num_guess, 2**(num_guess+1)):
    index = bin(i)[3:]
    
    with open('ANF_guessed.txt', 'w') as file:
        for line in ANF:
            file.write(line)
        for j in range(num_guess):
            if index[j] == '0':
                file.write("x(" + str(key_var_end - j) + ")\n")
            else:
                file.write("x(" + str(key_var_end - j) + ") + 1\n")
    
    print('Checking... ' + index + 'x'*(keysize - num_guess))
    # https://stackoverflow.com/questions/325463/launch-a-shell-command-with-in-a-python-script-wait-for-the-termination-and-ret
    os.system('../bosphorus/build/bosphorus --anfread ANF_guessed.txt --solvewrite solution > ./resolve_bosphorus.txt;') # time
    print('Finished checking ' + index + 'x'*(keysize - num_guess) + '\n')
    
    with open('solution', 'r') as file:
        if file.readline() != "Solution UNSAT\n":
            end_time = time.time() # commonly used technique
            result = file.readline().split()
            print('Found the bits, which turn out to be...')
            for j in range(keysize):
                print(int(result[-j-1][0] != '-'), end='')
    
    if end_time is not None:
        break

print('\n\nTotal elasped time: ' + str(end_time - start_time) + ' (s)')