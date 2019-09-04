import time

#start = time.ctime()
#stop = time.ctime()

file = open('constituicaofederal.txt')



dictionary = dict()

for line in file:
    line = line.rstrip()
    
    if line in dictionary :
        dictionary[line] = dictionary[line] + 1
    else:
        dictionary[line] = 1

file.close()

directory = 'constituicaoASCII.txt'

const = open(directory)
error = 0

start = time.clock()
for lin in const:
    lin = lin.rstrip()
    
    words = lin.rsplit()
    
    for w in words:
        if w in dictionary :
            continue
        else:
            error += 1
stop = time.clock()

timer = stop - start

timer = timer * 1000
print(timer, 'ms')