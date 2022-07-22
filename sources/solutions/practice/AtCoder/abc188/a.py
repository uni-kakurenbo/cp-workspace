x, y = map(int, input().split());
print("Yes" if max(x,y)-min(x,y) < 3 else "No");
