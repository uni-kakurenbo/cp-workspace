a, b, c, k = map(int, input().split());
s, t = map(int, input().split());
print(s*a + t*b if s+t < k else s*a + t*b - c*(s+t));
