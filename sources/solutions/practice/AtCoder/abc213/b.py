n = int(input());
a = list(map(int, input().split()));
b = sorted(a);
for i, v in enumerate(a):
    if v == b[-2]: exit(print(i+1));
