"""
ID: yuxilvk1
LANG: PYTHON3
TASK: friday
PROG: friday
"""
fin = open('friday.in', 'r')
n = int(fin.read().split()[0])
fin.close()

days_in_month = {}
rslt = {i: 0 for i in range(7)}
monitor = 0


class Data_7():
    def __init__(self, int_num):
        self.int_num = int_num % 7


def is_leap_year(years):
    global days_in_month
    if str(years).endswith('00'):
        if years % 400 == 0:
            days_in_month = {1: 31, 2: 31, 4: 31, 6: 31, 8: 31, 9: 31, 11: 31,
                             5: 30, 7: 30, 10: 30, 12: 30,
                             3: 29}
            return True
        else:
            days_in_month = {1: 31, 2: 31, 4: 31, 6: 31, 8: 31, 9: 31, 11: 31,
                             5: 30, 7: 30, 10: 30, 12: 30,
                             3: 28}
            return False
    else:
        if years % 4 == 0:
            days_in_month = {1: 31, 2: 31, 4: 31, 6: 31, 8: 31, 9: 31, 11: 31,
                             5: 30, 7: 30, 10: 30, 12: 30,
                             3: 29}
            return True
        else:
            days_in_month = {1: 31, 2: 31, 4: 31, 6: 31, 8: 31, 9: 31, 11: 31,
                             5: 30, 7: 30, 10: 30, 12: 30,
                             3: 28}
            return False

# Mon Tue Wed Thu Fri Sat Sun
# 0    1   2   3   4   5   6


def calculate(day, gap):
    add_up = gap % 7
    days = Data_7(day + add_up)
    return days.int_num


for year in range(1900, 1900 + n):
    a = is_leap_year(year)
    if a == True:
        for month in range(1, 13):
            monitor = calculate(monitor, days_in_month[month])
            rslt[monitor] += 1
    else:
        for month in range(1, 13):
            if year == 1900 and month == 1:
                monitor = 5  # 1900 Jan 13th is Sat.
                rslt[monitor] += 1
            else:
                monitor = calculate(monitor, days_in_month[month])
                rslt[monitor] += 1

fout = open('friday.out', 'w')
output_rule = [5, 6, 0, 1, 2, 3, 4]
output_str = ''
for index in output_rule:
    if index == 4:
        output_str = output_str + str(rslt[index]) + '\n'
    else:
        output_str = output_str + str(rslt[index]) + ' '
fout.write(output_str)

fout.close()
