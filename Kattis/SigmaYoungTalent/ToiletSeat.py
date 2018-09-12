s = input()
init = s[0]
def count1(): # up
    cnt = 0
    if init == 'D':
        cnt += 1
    else:
        if s[1] == 'D':
            cnt += 2
    for i in range(2, len(s)):
        if (s[i] == 'D'):
            cnt +=2
    return cnt

def count2(): # down
    cnt = 0
    if init == 'U':
        cnt += 1
    else:
        if s[1] == 'U':
            cnt += 2
    for i in range(2, len(s)):
        if (s[i] == 'U'):
            cnt +=2
    return cnt

def count3(): # as prefered
    cnt = 0
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            cnt +=1
    return cnt

print(count1())
print(count2())
print(count3())
