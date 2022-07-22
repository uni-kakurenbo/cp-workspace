a, b = input().split();
a = reversed(a);
b = reversed(b);
for i, j in zip(a, b):
    if int(i)+int(j) > 9: exit(print("Hard"));
print("Easy");
