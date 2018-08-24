fin = open('dualpal.in', 'r')
input = fin.readline().strip('\n').split(' ')
n = int(input[0])
s = int(input[1])
fin.close()

def tobase(n,b):
    if n == 0:
        return [0]
    d = []
    while n:
        d.append(int(n % b))
        n //= b
    return d[::-1]

def is_p_new(d_list):
    n = len(d_list)
    rslt = True
    for i in range(n):
        if d_list[i] != d_list[n-1-i]:
            rslt = False
    return rslt


fout = open('dualpal.out', 'w')
while True:
    for numbers in range(s + 1, 100000000000000):
        base_start = 2  # 2 3 4 5 6 7 8 9 10
        requirement = 2
        while base_start < 11 and requirement != 0:
            if is_p_new((tobase(numbers, base_start))):
                requirement -= 1
                base_start += 1
                if requirement == 0:
                    fout.write(str(numbers) + '\n')
                    n -= 1
                    if n == 0:
                        break
            else:
                base_start += 1
        if n == 0:
            break
    if n == 0:
        break

fout.close()
