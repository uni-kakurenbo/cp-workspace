n, k = map(int, input().split());
p = sorted(list(map(int, input().split())));
print(sum(p[:k]));
