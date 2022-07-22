n, x = map(int, input().split());
a = list(map(int, input().split()));
a = [v for v in a if v != x];
print(*a);
