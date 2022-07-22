h, w = map(int, input().split());
r, c = map(int, input().split());
ans = 4;
ans -= (r==1) + (r==h) + (c==1) + (c==w);
print(ans);
