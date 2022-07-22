a, b, c = map(int, input().split());
if a > b:
    print("Takahashi");
elif a < b:
    print("Aoki");
else:
    print("Takahashi" if c == 1 else "Aoki");
