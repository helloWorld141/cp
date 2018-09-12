n = int(input())
map = {}
for i in range(n):
    a, b = input().split()
    try:
        r = int(b)
        s = a
    except ValueError:
        r = int(a) / 2
        s = b
    map[r] = s
for k in sorted(map.keys()):
    print(map.get(k))