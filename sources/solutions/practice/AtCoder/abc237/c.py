from sys import setrecursionlimit, stderr;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

s = input();
front = back = 0;
for c in s:
    if c == "a": front+=1;
    else: break;
for c in reversed(s):
    if c == "a": back+=1;
    else: break;
s = s[front:len(s)-back];
print("Yes" if front <= back and [*s] == [*reversed(s)] else "No")
