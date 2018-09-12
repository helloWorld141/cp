n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])

def bcnn(a,b):
    import fractions
    ucln = fractions.gcd(a,b)
    return(a*b // ucln)

boi = 1
for i in range(n):
    boi = bcnn(boi,a[i])

def kiemtra(a):                     #kiem tra xem a co toan uoc 2 va 3 ko
    while (a % 2 == 0):
        a = a //2
    while (a % 3 == 0):
        a = a //3
    return(a==1)
res = 'Yes'
for i in range(n):
    a[i] = boi // a[i]
    if kiemtra(a[i]) == False:
        res = 'No'
        break

print(res)
    
####### bi tran khi nhan len so qua lon #########
