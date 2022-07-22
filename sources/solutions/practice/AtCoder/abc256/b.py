n = input()
A = [*map(int, input().split())]
bits = 0;
p = 0
for a in A:
  bits |= 1;
  bits <<= a;
  p += bin(bits >> 4).count('1');
  bits &= (1 << 4) - 1;
print(p)
