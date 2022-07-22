from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

s = input()
p = 0 < int(s[:2]) <= 12
q = 0 < int(s[2:]) <= 12
debug(int(s[:2]), int(s[2:]))
if p and not q: print("MMYY")
elif (not p) and q: print("YYMM")
elif p and q: print("AMBIGUOUS")
else: print("NA")
