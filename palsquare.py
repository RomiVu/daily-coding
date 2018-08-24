"""
ID: yuxilvk1
LANG: PYTHON3
TASK: palsquare
PROG: palsquare
"""

fin = open('palsquare.in', 'r')
input = fin.read().splitlines()
base = int(input[0])
fin.close()


def is_p(num_list):
    global print_out
    num = len(num_list)
    high = num_list[0][0]
    for item in num_list:
        if item[1] >= 10:
            item[1] = pair[item[1]]
    if num == 1 and num_list[0][0] != 0:
        rslt = False
    elif num == 1 and num_list[0][0] == 0:
        rslt = True
    else:
        indicator = True
        for i in range(num):
            if num_list[i][1] != num_list[num - i - 1][1] or num_list[i][0] != high - num_list[num - i - 1][0]:
                indicator = False
        if indicator == True:
            rslt = True
        else:
            rslt = False  # return true if num is  palsquare, e.g.. 10101, CF808FC, 6776, 010, 0000

    if rslt == True:
        pair_dict = {item[0]: item[1] for item in num_list}
        print_out = ''
        for i in range(high, -1, -1):
            if i in pair_dict.keys():
                print_out += str(pair_dict[i])
            else:
                print_out += '0'
        return True
    else:
        return False


def base_10_to_other(num_in_base10, target_base=base):
    # KNOWN number in base 10 not exceding 1, 2, 3, 4, ..., 299, 300
    # the square of the number above not exceding 90000
    # target base in range 2,3 ... 19, 20
    for i in range(17):
        if target_base ** i < num_in_base10 and target_base ** (i + 1) > num_in_base10:
            near_1 = target_base ** i
            for j in range(1, target_base):
                if j * near_1 < num_in_base10 and (j + 1) * near_1 > num_in_base10:
                    return i, j
                elif j * near_1 == num_in_base10:
                    return i, j
        elif target_base ** i == num_in_base10:
            return i, 1


a = []
print_out = ''

pair = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F', 16: 'G', 17: 'H', 18: 'I', 19: 'J', 20: 'K'}


def cal(num, base_t=base):
    global a
    x, y = base_10_to_other(num, base_t)
    value = num - y * base_t ** x
    if value == 0:
        a.append([x, y])
    else:
        a.append([x, y])
        cal(value, base_t)


b = []
print_i = ''


def trans_i(num, base_t=base):
    global b
    x, y = base_10_to_other(num, base_t)
    value = num - y * base_t ** x
    if value == 0:
        b.append([x, y])
    else:
        b.append([x, y])
        trans_i(value, base_t)


def p_i(num_list):
    global print_i
    num = len(num_list)
    high = num_list[0][0]
    for item in num_list:
        if item[1] >= 10:
            item[1] = pair[item[1]]

    pair_dict = {item[0]: item[1] for item in num_list}
    print_i = ''
    for i in range(high, -1, -1):
        if i in pair_dict.keys():
            print_i += str(pair_dict[i])
        else:
            print_i += '0'


fout = open('palsquare.out', 'w')
for i in range(1, 301):
    data = i ** 2
    a = []
    cal(data, base)
    if is_p(a):
        trans_i(i, base)
        p_i(b)
        b = []
        fout.write(str(print_i) + ' ' + str(print_out) + '\n')

fout.close()
