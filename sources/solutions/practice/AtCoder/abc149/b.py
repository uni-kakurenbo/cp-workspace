from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

a, b, k = map(int, input().split());
if a>=k: a-=k;
else:
  b-=min((k-a), b);
  a=0;
print(a, b);
