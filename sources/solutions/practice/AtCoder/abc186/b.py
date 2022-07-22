h, w = map(int, input().split());
A = [];
for _ in range(h):
    A.extend(list(map(int, input().split())));
m = min(A);
print(sum([A[i]-m for i in range(h*w)]));
