from sys import stderr;
def debug(*args):
  print(*args, file=stderr);
n = int(input());
for i in range(1, 10):
  if 1 <= n//i < 10 and n%i == 0: print("Yes"); exit();
print("No");
