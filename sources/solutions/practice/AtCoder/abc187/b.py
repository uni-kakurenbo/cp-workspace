n = int(input());
dots = [];
for _ in range(n):
    x, y = map(int, input().split());
    dots.append((x, y));

ans = 0;
for i in range(n-1):
    for j in range(i+1, n):
        if -1 <= (dots[i][1]-dots[j][1])/(dots[i][0]-dots[j][0]) <= 1:
            ans += 1;
            
print(ans);
