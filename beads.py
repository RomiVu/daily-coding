"""
ID: yuxilvk1
LANG: PYTHON3
TASK: beads
PROG: beads
"""

'''
def is_contiguous(index):
    if index == n - 1:
        if necklace_lt[index] == necklace_lt[0] or necklace_lt[0] == 'w':
            return True
        else:
            return False
    else:
        if necklace_lt[index] == 'w' or necklace_lt[index + 1] == 'w':
            return True
        else:
            if necklace_lt[index] == necklace_lt[index + 1]:
                return True
            else:
                return False
'''
'''
combination = []
count = 0
for i in range(n):
    if necklace_lt[i] == 'w':
        count += 1
    elif necklace_lt[i] == 'r':
        count += 1
    elif necklace_lt == 'b':
        count += 1
    else:
        combination.append(count)
        count = 0
'''


class Data():
    def __init__(self, _content, _amount, index_stop):
        self._content = _content
        self._amount = _amount
        self.index_stop = index_stop
        self.index_start = self.index_stop - self._amount

    def add_up(self, others):
        '''
        if self._content == others._content or others._content == 'w':
            if self.index_stop == others.index_start - 1:
                return self._amount + others._amount
            else:
                NotImplemented
        else:
            NotImplemented
        '''


fin = open('beads.in', 'r')
original_data = fin.read().splitlines()
n = int(original_data[0])
necklace_lt = list(original_data[1]) * 2
fin.close()
'''
original_data = ['wwwbbrwrbrbrrbrbrwrwwrbwrwrrb']
n = len(original_data[0])
necklace_lt = list(original_data[0]) * 2
'''
count = []
amount = 1
i = 0
vaildate_add_up = set()
while i != (2 * n - 1):
    if necklace_lt[i] != necklace_lt[i + 1]:
        count.append(Data(necklace_lt[i], 1, i + 1))
        i += 1
    else:
        while necklace_lt[i] == necklace_lt[i + 1]:
            i += 1
            amount += 1
            content = necklace_lt[i]
            if i == (2 * n - 1):
                i = i - 1
                amount = amount - 1
                break
        count.append(Data(content, amount, i + 1))
        amount = 1
        i += 1


def is_in_set_left(index):
    global vaildate_add_up
    if index == 0:
        vaildate_add_up.add(count[0]._content)
    else:
        if count[index]._content == 'w' or count[index - 1]._content == 'w':
            vaildate_add_up.add(count[index]._content)
            vaildate_add_up.add(count[index - 1]._content)
        else:
            vaildate_add_up.add(count[index]._content)


def is_in_set_right(index):
    global vaildate_add_up
    if index == len(count) - 1:
        vaildate_add_up.add(count[index]._content)
    else:
        if count[index]._content == 'w' or count[index + 1]._content == 'w':
            vaildate_add_up.add(count[index]._content)
            vaildate_add_up.add(count[index + 1]._content)
        else:
            vaildate_add_up.add(count[index]._content)


'''
try:
    for i in range(200):
        print(count[i]._content, count[i]._amount, count[i].index_start, count[i].index_stop)
except IndexError:
    print(i)
'''
max_num = 0


content_list = [items._content for items in count]
if len(set(content_list)) == 1:
    max_num = n
elif 'w' in set(content_list) and len(set(content_list)) == 2:
    max_num = n
else:
    for j in range(len(count) - 1):
        # left j,j-1,j-2,..., 0  step -1
        p = j
        is_in_set_left(p)
        left_amount_sum = 0
        while count[p]._content in vaildate_add_up and p in range(j, -1, -1):
            left_amount_sum += count[p]._amount
            p += -1
        vaildate_add_up = set()

        # right j+1,j+2,...,len(count) - 1 step 1
        q = j + 1
        is_in_set_right(q)
        right_amount_sum = 0
        while count[q]._content in vaildate_add_up and q in range(j + 1, len(count)):
            right_amount_sum += count[q]._amount
            if q == len(count) - 1:
                break
            q += 1
        vaildate_add_up = set()

        if (left_amount_sum + right_amount_sum) > max_num:
            max_num = left_amount_sum + right_amount_sum
if max_num > n:
    max_num = n

fout = open('beads.out', 'w')
fout.write(str(max_num) + '\n')
fout.close()
'''
a1 = count[0]  # w 3 0 3
a2 = count[1]  # b 2 3 5
a3 = count[2]  # r 1 5 6
a4 = count[3]  # w 1 6 7
a5 = count[4]  # r 1 7 8
a6 = count[5]  # b 1 8 9
a7 = count[6]  # r 1 9 10
a8 = count[7]  # b 1 10 11
a9 = count[8]  # r 2 11 13

print(Data.add_up(a3, a4, a5))
# print(combination)
'''
