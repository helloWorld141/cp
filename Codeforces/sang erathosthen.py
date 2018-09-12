
#tao sang nguyen to tu 1 den 100000
# sang Erathosthen O(N log N)
lim = 100000
E = [0]*lim
E[2] = E[3] = 1
for i in range(2,lim):
    if E[i] == 1:
        j=2
        #import pdb; pdb.set_trace()
        while (j*i<lim):
            E[j*i] = 2
            j+=1
    elif E[i] == 0:
        E[i] = 1
        j = 2
        while (j*i<lim):
            E[j*i] = 2
            j+=1
        
prime = []
for i in range(2,lim):
    if E[i] == 1:
        prime.append(i)

thuaso = []
import math, cmath
def phantich(x):
    
    global thuaso, prime
    can = math.floor(cmath.sqrt(x).real)
    while can not in prime:
        can -= 1
    ican = prime.index(can)
    for i in range(0,ican+1):
        #import pdb; pdb.set_trace()
        bac = 0
        while (x%prime[i] == 0):
            x = x/prime[i];
            bac += 1
        coso = prime[i]
        if (bac>0):
            thuaso.append(str(coso)+' '+str(bac))
        if x in prime:
            thuaso.append(str(int(x))+' '+str(1))
            break
        if x == 1: break

#xu li chinh
n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])
    print(a)
    #phantich(a[i])
    
print(phantich)

