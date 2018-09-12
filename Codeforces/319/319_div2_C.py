n = int(input())
a = [0]*(n+1)
nto = [1]*(n+1)

#tao mang nguyen to
nto[0] = nto[1] = 0
for i in range(2,n+1):
    if nto[i]==1:
        k = 2
        while k*i <= n:
            nto[k*i] = 0
            k += 1

#xuli
dem = 0
for i in range(n+1):
    if nto[i] == 1:
        k  = 1
        while i**k <= n:
            a[i**k] = 1
            k += 1
            dem += 1

print(dem)
for i in range(n+1):
    if a[i] == 1:
        print(str(i), end= ' ')
