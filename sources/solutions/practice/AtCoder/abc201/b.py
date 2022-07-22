n = int(input());
mp = {};
vec = [];
for _ in range(n):
    s, t = input().split();
    t = int(t);
    vec.append(t);
    mp[t] = s;
vec = sorted(vec);
print(mp[vec[-2]]);
