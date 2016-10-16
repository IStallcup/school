import sys
import random
import string

lowerstring = string.ascii_lowercase

randomjunk = random.choice(lowerstring)
for x in range(0,9):
	randomjunk = randomjunk + random.choice(lowerstring)

file = open('rand1','w+')
print randomjunk
file.write(randomjunk)
file.close()

randomjunk = random.choice(lowerstring)
for x in range(0,9):
	randomjunk = randomjunk + random.choice(lowerstring)

file = open('rand2','w+')
print randomjunk
file.write(randomjunk)
file.close()

randomjunk = random.choice(lowerstring)
for x in range(0,9):
	randomjunk = randomjunk + random.choice(lowerstring)

file = open('rand3','w+')
print randomjunk
file.write(randomjunk)
file.close()

randomnum1 = random.randint(1,42)
print randomnum1
randomnum2 = random.randint(1,42)
print randomnum2

print 'product of ' + str(randomnum1) + ' and ' + str(randomnum2) + ' is:'
print randomnum1 * randomnum2 
