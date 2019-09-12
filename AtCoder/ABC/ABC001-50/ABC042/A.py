a = list(map(int,input().split()))
haiku_5 = 2
haiku_7 = 1

num_5 = a.count(5)
num_7 = a.count(7)

if(num_5 == haiku_5 and num_7 == haiku_7):
    print('YES')
else:
    print('NO')
