"""s = input()
a = c =g =t =0
for i in range(len(s)):
    if (s[i] == 'A'):
        a+=1
    if (s[i] == 'C'):
        c+=1
    if (s[i] == 'G'):
        g+=1
    if (s[i] == 'T'):
        t+=1
print(str(a) + ' '+ str(c) + ' '+ str(g) + ' '+ str(t))"""

print(*map(input().count, "ACGT")) #elegent
