"""
ID: yuxilvk1
LANG: PYTHON3
TASK: crypt1
PROG: crypt1
"""
d_3 = list(range(111, 1000))

for i in range(111, 1000):
    if '0' in str(i):
        d_3.remove(i)

d_2 = list(range(11, 100))

for i in range(11, 100):
    if '0' in str(i):
        d_2.remove(i)
product_all = []
for i in d_3:
    for j in d_2:
        if len(str(i * j)) < 5 and '0' not in str(i * j):
            product_all.append([i, j, i * j])

with open('crypt1.in', 'r') as f:
    data = f.read().splitlines()

target = set(data[1])
target.discard(' ')

final_product = []
for item in product_all:
    if set(str(item[0])).issubset(target) and set(str(item[1])).issubset(target) and set(str(item[2])).issubset(target):
        d = str(item[1])
        x1 = int(d[0])
        x2 = int(d[1])
        n1 = x1 * item[0]
        n2 = x2 * item[0]
        if n1 <= 999 and n2 <= 999:
            # product_all.remove(item)
            if set(str(n1)).issubset(target) and set(str(n2)).issubset(target):
                final_product.append(item)
with open('crypt1.out', 'w') as f:
    f.write(str(len(final_product)) + '\n')
