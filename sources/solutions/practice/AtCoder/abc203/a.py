a, b, c = map(int, input().split());

if a != b and b != c and c != a:
    print(0);
else:
    print(a^b^c);
