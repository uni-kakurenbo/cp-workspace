a = list(map(int, input().split()));
a = sorted(a);
if a[2]-a[1] == a[1] - a[0]:
    print("Yes");
else:
    print("No");
