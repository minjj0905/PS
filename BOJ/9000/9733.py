import sys
from collections import Counter

arr = []
while(1):
    try:
        arr += input().split()
    except:
        break

len_arr = len(arr)
c = Counter(arr)

job_list = ['Re', 'Pt', 'Cc', 'Ea', 'Tb', 'Cm', 'Ex']

for job in job_list:
    sys.stdout.write(job + ' ')
    sys.stdout.write(str(c[job]) + ' ')
    sys.stdout.write(format(c[job]/len_arr, '.2f') + '\n')

sys.stdout.write('Total ' + str(len_arr) + ' 1.00' + '\n')