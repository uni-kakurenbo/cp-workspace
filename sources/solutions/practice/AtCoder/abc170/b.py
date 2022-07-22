x, y = map(int, input().split());
print("Yes" if y%2==0 and y <= x*4 <= y*2 else "No")
