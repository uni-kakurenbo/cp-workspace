a, b = map(int, input().split());
print("Impossible" if a%3 and b%3 and (a+b)%3  else "Possible");
