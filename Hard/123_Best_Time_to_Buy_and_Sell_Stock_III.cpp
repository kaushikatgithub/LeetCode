class Solution {
public:

    int solve(vector<int> &p, int bought, int cday, int k, vector<vector<vector<int>>> &dp)
    {
        
        if(k == 0) return 0;
        if(cday == p.size() && bought == 0) return 0;
        if(cday == p.size() && bought == 1) return -1e8;
        if(dp[bought][cday][k] != -1) return dp[bought][cday][k];

        int ans = 0;
        if(bought) ans = max(solve(p, bought, cday+1, k, dp), p[cday]+solve(p, 0, cday+1, k-1, dp));
        else ans = max(solve(p, bought, cday+1, k, dp), -p[cday] + solve(p, 1, cday+1, k, dp));
        
        return dp[bought][cday][k] = ans;
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (n+1, vector<int> (3, -1)));
        return solve(p, 0, 0, 2, dp);
    }
};
