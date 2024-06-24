class Solution {
public:

    long long bfs(vector<vector<int>> &adj, int src, vector<bool> &vis)
    {
        long long count = 1;
        vis[src] = true;
        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto &v: adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }
        // cout << count << " ";
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n, vector<int> ());
        for(auto &edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long ans = 0;
        vector<bool> vis(n, false);
        for(int i=0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                long long cnt = bfs(adj, i, vis);
                ans += (n - cnt) * cnt;
            }
        }
        return ans/2;
    }
};
