"""
ID: yuxilvk1
LANG: PYTHON3
TASK: namenum
PROG: namenum
"""

fin = open('namenum.in', 'r')
n_str = fin.readline().strip('\n')
n = len(n_str)
fin.close()
'''
with open('test003.txt', 'r') as f:
    n_str = f.readline().strip('\n')
    n = len(n_str)
'''
pair = {'2': {'A', 'B', 'C'}, '5': {'J', 'K', 'L'}, '8': {'T', 'U', 'V'},
        '3': {'D', 'E', 'F'}, '6': {'M', 'N', 'O'}, '9': {'W', 'X', 'Y'},
        '4': {'G', 'H', 'I'}, '7': {'P', 'R', 'S'}}
indicator = []
for i in n_str:
    indicator.append(pair[i])

a = []
f = open('dict.txt', 'r')
#f = open('dict.txt', 'r')

a = [line.strip('\n') for line in f if len(line) == n + 1 and line[0] in indicator[0]]

f.close()


def check(s):
    # n > 1 situations
    rslt = True
    for i in range(1, n):
        if s[i] not in indicator[i]:
            rslt = False
    return rslt
    # pass


fout = open('namenum.out', 'w')
output = []
if len(a) == 0:
    output = []
else:
    if n == 1 or len(a) == 1:
        output = a
    else:
        for item in a:
            if check(item):
                output.append(item)

if len(output) == 0:
    fout.write('NONE' + '\n')
else:
    for item in output:
        fout.write(item + '\n')

fout.close()
