n = int(input());
a = list(map(int, input().split()));
b = list(map(int, input().split()));
print(max(min(b) - max(a) + 1, 0));
