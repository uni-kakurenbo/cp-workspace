from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

S = input();
print("Yes" if S[::2].count("L") <= 0 and S[1::2].count("R") <= 0  else "No")
