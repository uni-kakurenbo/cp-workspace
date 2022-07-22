a = int(input());
b = int(input());
n = int(input());
from numpy import lcm;
print(((n+lcm(a, b)-1)//lcm(a, b)) * lcm(a, b));
