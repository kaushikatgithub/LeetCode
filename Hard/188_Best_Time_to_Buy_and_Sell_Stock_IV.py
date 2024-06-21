class Solution:
    def maxProfit(self, k: int, p: List[int]) -> int:
        
        n = len(p)
        dp = [[[-1 for i in range(k+1)] for j in range(n+1)] for t in range(2)]

        def solve(bought, cday, k):
            if k == 0: 
                return 0
            if cday == n:
                return 0 if bought == 0 else -1e8
            if dp[bought][cday][k] != -1:
                return dp[bought][cday][k]
            
            ans = 0
            if bought == 1:
                ans = max(solve(bought, cday+1, k), p[cday] + solve(0, cday+1, k-1))
            else:
                ans = max(solve(bought, cday+1, k), -p[cday] + solve(1, cday+1, k))
            
            dp[bought][cday][k] = ans
            return ans
        
        return solve(0, 0, k)
