from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input());
s = input();
print(s.count("ABC"));
