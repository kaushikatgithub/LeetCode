class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        
        vis = [False] * (n+1)
        adj = [[] for i in range(n+1)]
        for road in roads:
            adj[road[0]].append((road[1], road[2]))
            adj[road[1]].append((road[0], road[2]))

        def bfs(src):

            ans = int(1e8)
            q = deque()
            vis[src] = True
            q.append(src)

            while q:
                u = q.popleft()
                for pv in adj[u]:
                    if not vis[pv[0]]:
                        vis[pv[0]] = True
                        q.append(pv[0])
                    ans = min(ans, pv[1])
            return ans
        
        ans = int(1e8)
        for i in range(1, n+1):
            if not vis[i] and not vis[1] and not vis[n]:
                ans = min(ans, bfs(i))
            else:
                return ans
        return ans
