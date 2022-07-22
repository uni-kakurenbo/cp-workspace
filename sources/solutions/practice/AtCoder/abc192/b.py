s = input();
even = s[0::2];
odd = s[1::2];
flag = all([c == c.lower() for c in even]);
flag &= all([c == c.upper() for c in odd]);
print("Yes" if flag else "No");
