n = input();
s = input();
turn = 1;
for c in s:
    if c=='1': exit(print("Takahashi" if turn == 1 else "Aoki"));
    turn *= -1;
