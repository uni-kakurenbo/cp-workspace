a, b, c = map(int, input().split());
print("Yes" if max(a, b, c)*2 == a+b+c else "No");
