a, b, w = map(int, input().split());
w *= 1000;

x = (w+b-1)//b; y = w//a;
if y < x: exit(print("UNSATISFIABLE"));
print(x, y);
