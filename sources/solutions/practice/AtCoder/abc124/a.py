a, b = map(int, input().split());
print(max(a, b)*2-1 if a != b else a*2);
