class Solution {
public:
    // We will treat the graph as an undirected one but
    // Here we create adjacency list with extra parameter correctness. 
    // then we do dfs from 0.
    // If we go through correct edge the no flips but if its incorrect edge then add one to flip
    // Since there is only one way between any two cities the answer will be minimum

    void dfs(vector<vector<pair<int, int>>> &adj, int src, int &flips, vector<bool> &vis)
    {
        vis[src] = true;
        for(auto &pv: adj[src])
        {
            if(!vis[pv.first])
            {
                flips += pv.second;
                dfs(adj, pv.first, flips, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>> ());    
        for(auto &connection: connections)
        {
            adj[connection[0]].push_back({connection[1], 1}); // 1 - correct
            adj[connection[1]].push_back({connection[0], 0}); // 0 - incorrect
        }

        int flips = 0;
        vector<bool> vis(n, false);
        dfs(adj, 0, flips, vis);
        return flips;
    }
};
