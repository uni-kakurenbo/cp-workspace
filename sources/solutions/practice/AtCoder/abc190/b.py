n, s, d = map(int, input().split());
flag = False;
for _ in range(n):
    x, y = map(int, input().split());
    flag |= x < s and y > d;
    if flag: break;
print("Yes" if flag else "No");

