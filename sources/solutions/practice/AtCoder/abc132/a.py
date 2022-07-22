s = input();
print("Yes" if len(set(list(s))) == 2 and s.count(s[0]) == 2 else "No");
