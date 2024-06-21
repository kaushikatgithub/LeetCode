class Solution:
    def maxProfit(self, p: List[int]) -> int:
        
        n = len(p)
        dp = [[-1 for i in range(n+1)] for j in range(3)] 

        def solve(bought, cday):
           
            if cday >= n:
                return 0 if bought == 0 else -1e8
            if dp[bought][cday] != -1:
                return dp[bought][cday] 

            ans = 0
            if bought == 1:
                ans = max(solve(bought, cday+1), p[cday] + solve(0, cday+2))
            else:
                ans = max(solve(bought, cday+1), -p[cday] + solve(1, cday+1))
            
            dp[bought][cday] = ans
            return ans
        return solve(0, 0)
