class istream():
    import sys

    def __init__(self, source = sys.stdin):
        self.pos = -1
        self.buffer = []
        self.source = source

    def one(self):
        self.pos += 1
        if self.pos >= len(self.buffer): self.buffer.extend(self.source.readline().split())
        return self.buffer[self.pos]

    def __call__(self, *types):
        if len(types) == 0: return str(self.one())

        if len(types) == 1:
            tp, count = types[0], 1
            if isinstance(tp, int):
                tp, count = str, tp
            if count == 1:
                return tp(self.one())
            else:
                return tuple(tp(self.one()) for _ in [0] * count)

        if len(types) == 2 and isinstance(types[1], int):
            return tuple(types[0](self.one()) for _ in [0] * types[1])

        return tuple(map(lambda type: type(self.one()), types))

    def line(self, type):
        return tuple(map(type, self.source.readline().split()))

cin = istream()
# cin = istream(sys.stdin)

a = cin(int)
print(a)

a = cin()
print(a)

a, b, c = cin(int,int,str)
print(a, b, c)

a, b, c = cin.line(int)
print(a, b, c)

a = cin(3)
print(a)

a = cin(int, 5)
print(a)
