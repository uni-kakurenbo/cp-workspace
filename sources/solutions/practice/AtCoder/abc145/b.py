from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input());
S = input();
debug(S[:n//2], S[n//2:])
print("Yes" if S[:n//2] ==  S[n//2:] else "No");
