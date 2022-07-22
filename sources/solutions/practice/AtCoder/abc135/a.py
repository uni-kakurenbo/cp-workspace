a, b = map(int, input().split());
res = (a+b)/2;
print("IMPOSSIBLE" if res != int(res) else int(res));
