s, t = input().split();
a, b = map(int, input().split());
u = input();
if u==s: a -= 1;
else: b -= 1 if u==t else 0;
print(a, b);
