class Solution:
    def closedIsland(self, g: List[List[int]]) -> int:
        
        M = len(g)
        N = len(g[0])
        delta = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        vis = [[False] * N for i in range(M)]

        def dfs(i, j, zero):
            vis[i][j] = True
            for k in range(4):
                x = i + delta[k][0]
                y = j + delta[k][1]
                if x < 0 or y < 0 or x == M or y == N or g[x][y] == int(zero) or vis[x][y]:
                    continue
                dfs(x, y, zero)

        for i in range(M):
            if not vis[i][0]:
                dfs(i, 0, g[i][0] ^ 1)
            if not vis[i][N - 1]:
                dfs(i, N - 1, g[i][N - 1] ^ 1)

        for j in range(N):
            if not vis[0][j]:
                dfs(0, j, g[0][j] ^ 1)
            if not vis[M - 1][j]:
                dfs(M - 1, j, g[M - 1][j] ^ 1)

        count = 0
        for i in range(1, M - 1):
            for j in range(1, N - 1):
                if vis[i][j]:
                    continue
                if g[i][j] == 0:
                    dfs(i, j, True)
                    count += 1
                else:
                    vis[i][j] = True
        return count
