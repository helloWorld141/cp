import math
s = (input().split())
n = int(s[0])
x = int(s[1])
dem = 0
if n > math.trunc(math.sqrt(x)):
    m = int(math.trunc(math.sqrt(x)))
else:
    m = n
for i in range(1,m+1):
    if x % i == 0 :
        if (x/i <= n)and(i <=n)and(x/i != i) :
            dem += 2
        elif x/i == i:
            dem +=1
print(dem)
