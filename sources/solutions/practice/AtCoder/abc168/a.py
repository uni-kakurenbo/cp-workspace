n = int(input());
n = n%10;
if n in [0, 1, 6, 8]:
    print("pon");
elif n == 3:
    print("bon");
else:
    print("hon");
