a = list(map(int,input().split()))
volume = 1
while(len(a)):
    volume *= a.pop()
ans = volume % (pow(10,9)+7)

print(ans)
