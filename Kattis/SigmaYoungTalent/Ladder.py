from math import sin, radians, cos, ceil
h, v = input().split()
h = int(h)
v = int(v)
print(ceil(h/sin(radians(v))))