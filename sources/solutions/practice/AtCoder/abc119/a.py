s = input();
y = int(s[0:4]);
m = int(s[5:7]);
d = int(s[8:10]);
print("Heisei" if (y,m,d) <= (2019, 4, 30) else "TBD");
