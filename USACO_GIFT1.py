"""
ID: yuxilvk1
LANG: PYTHON3
TASK: gift1
PROG: gift1
"""
import re

fin = open('gift1.in', 'r')

def cal_balance(group_list):
    for item in group_list:
        a, b = map(int, item[1].split())
        if b == 0:
            np_balance[item[0]].append(a)
        else:
            left = a % b
            average = (a - left) // b
            np_balance[item[0]].append(left - a)
            for elements in item[2:]:
                np_balance[elements].append(average)


def gen_group(data):
    pattern = re.compile(r'\d+ \d+')  # find the string like '000 000'
    for i in range(len(data)):
        if pattern.match(data[i]):
            num_persons = int(data[i].split()[1])
            group.append(data[i - 1: i + num_persons + 1])


original_data = fin.read().splitlines()
np = int(original_data[0])
np_names = [original_data[i] for i in range(1, np + 1)]
np_balance = {j: [] for j in np_names}
group = []
gen_group(original_data)  # to generate groups for calculation in next step
cal_balance(group)  # to generate dict of all transaction data

fout = open('gift1.out', 'w')
for key in np_names:
    fout.write(key + ' ' + str(int(sum(np_balance[key]))) + '\n')
fin.close()
fout.close()
