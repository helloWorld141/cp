n = int(input())
s = input().split()
xay = pha = 0
a = [0]*(n+2)                   # tu 0 den n+1
for i in range(1,n+1):
    a[i] = int(s[i-1])
    xay += a[i]

def demgach(l,r):
    #import pdb; pdb.set_trace()
    global pha,t,p
    dap = [0]*(n+1)
    for i in range(l,r):
        if a[i] == 0:
            pass
        elif a[i] <= a[i-1] and a[i] <= a[i+1]:
            dap[i] = 1
        else:
            dap[i] = max((a[i]-a[i-1]),(a[i]-a[i+1]))
        pha += dap[i]
        
    for i in range(l,r):
        a[i] = a[i] - dap[i]
        
    for i in range(1,n):
        if (a[i] == 0)and(a[i+1] != 0):
            t = i+1
            break
    for i in range(n,0,-1):
        if (a[i] == 0)and(a[i-1] != 0):
            p = i
            break



t = 1; p = n+1
solan = 0
while pha < xay:
    demgach(t,p)
    solan += 1
    
print(solan)
