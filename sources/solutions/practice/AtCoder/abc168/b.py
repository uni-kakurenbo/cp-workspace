k = int(input());
s = input();
print(s if len(s) <= k else s[:k] + "...");
