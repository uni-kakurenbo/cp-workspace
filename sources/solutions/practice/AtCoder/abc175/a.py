s = input();
if s == "RRR":
    print(3);
elif s == "RRS" or s == "SRR":
    print(2);
elif s == "RSR" or s.count("R") == 1:
    print(1);
else:
    print(0);
