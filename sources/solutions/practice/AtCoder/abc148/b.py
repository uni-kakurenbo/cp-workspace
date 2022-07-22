from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input());
S, T = input().split();
ans = "";
for s, t in zip(S, T):
  ans += s + t;
print(ans);
