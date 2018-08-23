"""
ID: yuxilvk1
LANG: PYTHON3
TASK: transform
PROG: transform
"""
from collections import namedtuple
Point = namedtuple('Point', ['x', 'y', 'v'])

fin = open('transform.in', 'r')
input = fin.read().splitlines()
n = int(input[0])
fin.close()

shift = (n - 1) / 2
matrix_before = []
matrix_after = []
for i in range(n):
    for j in range(n):
        matrix_before.append(Point(i - shift, j - shift, input[i + 1][j]))
        matrix_after.append(Point(i - shift, j - shift, input[i + n + 1][j]))

del(input)
dict_2 = {(item.x, item.y): item.v for item in matrix_after}
del(matrix_after)


def sin_cos(degrees):
    if degrees == 360:
        return 0, 1
    elif degrees == 270:
        return -1, 0
    elif degrees == 180:
        return 0, -1
    elif degrees == 90:
        return 1, 0


def rotate(matrix, degree, r=1):
    # if r == 1, then just rotate; else do the combination.
    rslt_temp = []
    for i in range(n ** 2):
        point = matrix[i]
        c1, c2 = sin_cos(degree)
        if r == 1:
            x = point.x * c2 + point.y * c1
            y = point.y * c2 - point.x * c1
        else:
            x = point.x * c2 - point.y * c1
            y = -point.y * c2 - point.x * c1
        v = point.v
        rslt_temp.append(Point(x, y, v))
    return rslt_temp


def is_equal(list_1):
    dict_1 = {(item.x, item.y): item.v for item in list_1}
    if dict_1 == dict_2:
        return True
    else:
        return False


rotate_option_1 = [90, 180, 270, 360]
rotate_option_2 = [360, 90, 180, 270]


def find():
    for dg_1 in rotate_option_1:
        if is_equal(rotate(matrix_before, dg_1, r=1)):
            return dg_1, 1
    for dg_2 in rotate_option_2:
        if is_equal(rotate(matrix_before, dg_2, r=0)):
            return dg_2, 0
    return None, None


a, b = find()


fout = open('transform.out', 'w')

if b == None:
    fout.write(str(7) + '\n')
elif b == 1:
    if a == 90:
        fout.write(str(1) + '\n')
    elif a == 180:
        fout.write(str(2) + '\n')
    elif a == 270:
        fout.write(str(3) + '\n')
    elif a == 360:
        fout.write(str(6) + '\n')
elif b == 0:
    if a in {90, 180, 270}:
        fout.write(str(5) + '\n')
    elif a == 360:
        fout.write(str(4) + '\n')

fout.close()

