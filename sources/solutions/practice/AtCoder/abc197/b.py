h, w, x, y = map(int, input().split());
S = ["#" * (w+2)];
for _ in range(h):
    S.append("#" + input() + "#");
S.append("#" * (w+2));

ans = 0;
i = x; j = y;
while S[i][j] == ".":
    ans += 1;
    i += 1;
i = x; j = y;
while S[i][j] == ".":
    ans += 1;
    i += -1;
i = x; j = y;
while S[i][j] == ".":
    ans += 1;
    j += 1;
i = x; j = y;
while S[i][j] == ".":
    ans += 1;
    j += -1;
ans -= 3;
print(max(ans,0));
