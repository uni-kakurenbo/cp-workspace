from itertools import product;
a = [int(input()) for _ in range(5)];
k = int(input());
print(":(" if a[-1]-a[0] > k else "Yay!");
