n = list(input());
n.reverse()
last = 0;
for i, c in enumerate(n):
    if c != '0': break;
    else: last = i+1;
n = n[last:];
print("Yes" if n == n[::-1] else "No");
