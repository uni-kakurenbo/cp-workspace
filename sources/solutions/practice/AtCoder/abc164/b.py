a, b, c, d = map(int, input().split());
print("Yes" if (c+b-1)//b <= (a+d-1)//d else "No")
