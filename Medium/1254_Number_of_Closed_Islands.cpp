class Solution {
public:

    int M, N;
    int del[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &g, int i, int j, bool zero, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        int x, y;
        for(int k=0 ; k<4 ; k++)
        {
            x = i + del[k][0];
            y = j + del[k][1];
            if(x<0 || y<0 || x==M || y==N || g[x][y] == zero || vis[x][y]) continue;
            dfs(g, x, y, zero, vis);
        }
    }

    int closedIsland(vector<vector<int>>& g) {
        
        M = g.size();
        N = g[0].size();
        vector<vector<bool>> vis(M, vector<bool> (N, false));
        
        for(int i=0 ; i<M ; i++)
        {
            if(!vis[i][0]) dfs(g, i, 0, g[i][0] ^ 1, vis);
            if(!vis[i][N-1]) dfs(g, i, N-1, g[i][N-1] ^ 1, vis);
        }

        for(int j=0 ; j<N ; j++)
        {
            if(!vis[0][j]) dfs(g, 0, j, g[0][j] ^ 1, vis);
            if(!vis[M-1][j]) dfs(g, M-1, j, g[M-1][j] ^ 1, vis);
        }

        int count = 0;
        for(int i=1 ; i<M-1 ; i++)
        {
            for(int j=1 ; j<N-1 ; j++)
            {
                if(vis[i][j]) continue;
                if(g[i][j] == 0)
                {
                    dfs(g, i, j, true, vis);
                    count++;
                }else
                {
                    vis[i][j] = true;
                }
            }
        }
        return count;
    }
};
