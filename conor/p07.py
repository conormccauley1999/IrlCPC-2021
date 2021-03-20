import sys
sys.setrecursionlimit(20000)

G = []
V = []
n = 0
m = 0

def s(i, j):
    global n, m
    return i >= 0 and i < n and j >= 0 and j < m

def dfs(i, j):
    global G, V, n, m
    if V[i][j]: return
    V[i][j] = True
    if s(i + 1, j) and G[i+1][j]: dfs(i + 1, j)
    if s(i - 1, j) and G[i-1][j]: dfs(i - 1, j)
    if s(i, j + 1) and G[i][j+1]: dfs(i, j + 1)
    if s(i, j - 1) and G[i][j-1]: dfs(i, j - 1)

def main():
    global G, V, n, m
    n, m = map(int, input().split())
    if n == 0 or m == 0:
        print(0)
        return
    G = []
    V = []
    for _ in range(n):
        G.append([*map(int, input().split())])
        V.append([False] * m)
    cnt = 0
    for i in range(n):
        for j in range(m):
            if not V[i][j] and G[i][j]:
                dfs(i, j)
                cnt += 1
    for i in range(n):
        for j in range(m):
            if not G[i][j]:
                continue
            t = 0
            xx = 4
            if not s(i + 1, j): xx -= 1
            if not s(i - 1, j): xx -= 1
            if not s(i, j + 1): xx -= 1
            if not s(i, j - 1): xx -= 1
            if s(i + 1, j) and not G[i+1][j]: t += 1
            if s(i - 1, j) and not G[i-1][j]: t += 1
            if s(i, j + 1) and not G[i][j+1]: t += 1
            if s(i, j - 1) and not G[i][j-1]: t += 1
            if t >= xx: cnt -= 1
    print(cnt)

main()
