p = int(input());
coins = [1];
for i in range(2, 11):
    coins.append(coins[-1]*i);
coins.reverse();
ans = 0; rest = p;
while rest > 0:
    for coin in coins:
        if rest >= coin: rest -= coin; ans+=1; break;
print(ans);
