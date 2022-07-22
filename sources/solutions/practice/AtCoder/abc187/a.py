a, b = map(int, input().split());
def sum_digits(x):
    res = 0;
    while x:
        res += x%10;
        x //= 10;
    return res;
print(max(sum_digits(a), sum_digits(b)));
