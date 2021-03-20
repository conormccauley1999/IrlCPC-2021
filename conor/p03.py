import os
import sys
from io import BytesIO, IOBase
from math import factorial
INF = 10 ** 10
MOD = (10 ** 9) + 7

def g(bits):
    if bits <= 4:
        return 0
    else:
        return pow(2, bits - 4)

def f(bits):
    DIFF = lambda x: x + 3
    dp = []
    for _ in range(bits): dp.append([0] * 7)
    dp[0][DIFF(-1)] = dp[0][DIFF(1)] = 1
    for i in range(1, bits):
        for d in range(-3, 4):
            if d > -3: dp[i][DIFF(d-1)] += dp[i-1][DIFF(d)]
            if d < 3: dp[i][DIFF(d+1)] += dp[i-1][DIFF(d)]
    return sum(dp[-1]) - g(bits)

def main():
    n = int(input())
    i = 1
    while i < 64 and f(i) < n:
        i += 1
    print(i)

# region fastio

BUFSIZE = 8192

class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()
