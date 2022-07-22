x, y = map(int, input().split());
a = [ 1, 3, 5, 7, 8, 10, 12 ];
b = [ 4, 6, 9, 11 ];
c = [ 2 ];
if x in a:
    print("Yes" if y in a else "No");
elif x in b:
    print("Yes" if y in b else "No");
else:
    print("Yes" if y in c else "No");
