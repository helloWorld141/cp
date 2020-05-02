MOD = 10**9
def solve(s):
    x = y = 0
    m = 1
    st = []
    for c in s:
        if '1' < c <= '9':
            m = (int(c) * m)
            st.append(int(c))
        elif c == ')':
            m /= st[-1]
            st.pop()
        elif c == '(':
            continue
        else:
            if c == 'N':
                y = y-m
            if c == 'S':
                y = y+m
            if c == 'E':
                x = x+m
            if c == 'W':
                x = x-m
    return x%MOD + 1, y%MOD + 1

import sys
size = int(sys.argv[1])
input = ''
for i in range(size):
    input += '9('
for i in range(size):
    input += 'E)'
print(solve(input))