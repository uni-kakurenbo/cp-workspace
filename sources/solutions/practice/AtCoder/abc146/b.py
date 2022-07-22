from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input());
S = input();
T = "";
for c in S:
  T += chr((ord(c)-ord("A")+n)%26+ord("A"));
print(T);
