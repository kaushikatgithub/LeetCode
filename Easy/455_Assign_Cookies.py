class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        
        m = len(g)
        n = len(s)

        g.sort()
        s.sort()

        i = 0
        j = 0
        ans = 0

        while i < m and j < n:
            if g[i] <= s[j]:
                ans += 1
                i += 1
                j += 1
            else:
                j += 1
        return ans
