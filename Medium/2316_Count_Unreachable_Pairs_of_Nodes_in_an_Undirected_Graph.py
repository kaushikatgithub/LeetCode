class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        
        adj = [[] for i in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        ans = 0
        vis = [False] * n

        def bfs(src):
            count = 1
            vis[src] = True
            q = deque([src])

            while q:
                u = q.popleft()
                for v in adj[u]:
                    if not vis[v]:
                        vis[v] = True
                        count += 1
                        q.append(v)
            return count
        
        for i in range(n):
            if not vis[i]:
                cnt = bfs(i)
                ans += (n - cnt) * cnt
        return ans // 2
