n = int(input())
j = 0
s = input()
a = s.split()
for i in range(n):
    a[i] = int(a[i])

    
def findmax():
    #import pdb; pdb.set_trace()
    global max1, max2, imax1, imax2, a
    max2 = 0
    imax2 = imax1 = 0
    max1 = max(a)
    for i in range(n-1,-1,-1):
        if a[i]==max1:
            imax1 = i
            break
    for i in range(n):
        if (max1>=a[i]>=max2)&(i != imax1):
            max2 = a[i]
            imax2 = i
    return 1

c = 1
findmax()
if (max1 == a[0])&(max1 not in a[1:n]):
    pass
else:
    while c==1:
       # import pdb; pdb.set_trace()
        findmax()
        while (max1 >= max2)&(max1 >= a[0]):
            max1-=1
            a[imax1]-=1
            a[0]+=1
            j+=1
            #print(a)
        else:
            if (a[0]>max1)&(a[0]>max2):
                c=0
            

print(j)
