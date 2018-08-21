"""
ID: yuxilvk1
LANG: PYTHON3
TASK: milk2
PROG: milk2
"""

fin = open('milk2.in', 'r')
original_data = fin.read().splitlines()
n = int(original_data[0])
data = [item.split(' ') for item in original_data[1:n + 1]]
int_data = [[int(data[i][j]) for j in range(2)] for i in range(n)]
fin.close()


class Data_Type():
    def __init__(self, begin, end, interval_no=0, interval_con=None):
        self.begin = begin
        self.end = end
        self.interval_no = interval_no
        if interval_con == None:
            self.interval_con = self.end - self.begin
        else:
            self.interval_con = interval_con

    def combination(self, others):
        if others.begin >= self.begin and others.begin <= self.end:
            _b = self.begin
            if self.end >= others.end:
                _e = self.end
            else:
                _e = others.end
            return Data_Type(_b, _e)
        elif others.begin > self.end:
            _b = self.begin
            _e = others.end
            gap = others.begin - self.end
            contious = max(self.interval_con, others.interval_con)
            return Data_Type(_b, _e, gap, contious)
        elif others.begin < self.begin:
            _b = others.begin
            if others.end > self.begin:
                _e = self.end
                gap = others.end - self.begin
                contious = max(self.interval_con, others.interval_con)
                return Data_Type(_b, _e, gap, contious)
            elif others.end >= self.begin and others.end <= self.end:
                _e = self.end
                return Data_Type(_b, _e)
            else:
                _e = others.end
                return Data_Type(_b, _e)


trans_data = []
for i in range(n):
    trans_data.append(Data_Type(int_data[i][0], int_data[i][1]))
trans_data = sorted(trans_data, key=lambda item: item.begin)

rslt = []
if n == 1:
    rslt = trans_data
else:
    index = 0
    while index <= n - 2:
        a = Data_Type.combination(trans_data[index], trans_data[index + 1])
        if a.interval_no == 0:
            index += 1
            trans_data[index] = a
            if index == n - 1:
                rslt.append(trans_data[index])
                break
        else:
            rslt.append(trans_data[index])
            index += 1
            if index == n - 1:
                rslt.append(trans_data[index])
                break
output_no = 0
output_con_list = []
for item in rslt:
    output_con_list.append(item.interval_con)
output_con = max(output_con_list)
if len(rslt) == 1:
    output_no = 0
else:
    for i in range(len(rslt) - 1):
        temp_no = rslt[i + 1].begin - rslt[i].end
        if temp_no > output_no:
            output_no = temp_no


fout = open('milk2.out', 'w')
fout.write(str(output_con) + ' ' + str(output_no) + '\n')
fout.close()
