s, t, x = map(int, input().split());

if s < t :
    if s <= x and x < t :
        print("Yes");
    else:
        print("No");
else:
    if x < t or s <= x :
        print("Yes");
    else:
        print("No");
