class Solution {
public:
    int Fee;
    int solve(vector<int> &p, int bought, int cday, vector<vector<int>> &dp)
    {
        if(p.size() <= cday)
        {
            if(bought == 0) return 0;
            else return -1e8;
        }

        if(dp[cday][bought] != -1) return dp[cday][bought];

        int ans = 0;
        if(bought)
        {
            ans = max(solve(p, bought, cday+1, dp), p[cday] - Fee + solve(p, 0, cday+1, dp)); 
        }else
        {   
            ans = max(solve(p, bought, cday+1, dp), -p[cday] + solve(p, 1, cday+1, dp));
        }
        return dp[cday][bought] = ans;
    }
    int maxProfit(vector<int>& p, int fee) {
        Fee = fee;
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int> (3, -1));
        return solve(p, 0, 0, dp);
    }
};
