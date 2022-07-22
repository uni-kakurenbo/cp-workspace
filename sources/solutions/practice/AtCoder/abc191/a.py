v, t, s, d = map(int, input().split());
if t <= d/v and d/v <= s:
    print("No");
else:
    print("Yes");
