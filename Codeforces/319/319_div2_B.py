n,m = map(int, input().split())
if n > m:
    print("YES")
    exit()

a = [int(i) for i in input().split()]
#import pdb;pdb.set_trace()

# khoi tao dieu kien ban dau QHD
can = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    can[i][a[i]%m] = 1

# QHD
for i in range(n-1):
    for j in range(m):
        if can[i][j] == 1 :
            can[i+1][j] = 1
            can[i+1][(j+a[i+1])%m] = 1
            
if can[n-1][0] :
    print("YES")
else:
    print("NO")
