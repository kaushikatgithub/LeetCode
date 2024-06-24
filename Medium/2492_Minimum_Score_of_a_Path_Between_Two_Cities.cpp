class Solution {
public:

    int bfs(vector<vector<pair<int, int>>> &adj, int src, vector<bool> &vis)
    {
        int ans = 1e8;
        queue<int> q;
        vis[src] = true;
        q.push(src);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto &pv: adj[u])
            {
                if(!vis[pv.first])
                {
                    vis[pv.first] = true;
                    q.push(pv.first);
                }
                ans = min(ans, pv.second);
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>> ());
        for(auto &road: roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        int ans = 1e8;
        vector<bool> vis(n+1, false);
        for(int i=1 ; i<=n ; i++)
        {
            if(!vis[i] && !vis[1] && !vis[n])
            {
                ans = min(ans, bfs(adj, i, vis));
            }else
            {
                return ans;
            }
        }
        return ans;
    }
};
