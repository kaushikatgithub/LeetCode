class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        adj = [[] for i in range(n)]
        for connection in connections:
            adj[connection[0]].append((connection[1], 1))  # 1 - correct
            adj[connection[1]].append((connection[0], 0))  # 0 - incorrect


        vis = [False] * (n)
        flips = 0

        def dfs(src):
            nonlocal flips
            vis[src] = True
            for pv in adj[src]:
                if not vis[pv[0]]:
                    flips += pv[1]
                    dfs(pv[0])
        
        dfs(0)
        return flips
