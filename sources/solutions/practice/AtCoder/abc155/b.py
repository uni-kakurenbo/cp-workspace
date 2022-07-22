n = int(input());
A = list(map(int, input().split()));
print("APPROVED" if n == sum([1 if a%2!=0 or a%2==0 and (a%3==0 or a%5==0) else 0 for a in A]) else "DENIED")
