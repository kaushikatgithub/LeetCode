class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        
        n = len(nums)
        if n < 3:
            return 0
        
        t_cnt, ap_cnt = 0, 0
        for i in range(0, n-2):
            if nums[i+1]-nums[i] == nums[i+2]-nums[i+1]:
                t_cnt += 1
            else:
                ap_cnt += (t_cnt)*(t_cnt+1)//2
                t_cnt = 0
        
        if t_cnt:
            ap_cnt += (t_cnt)*(t_cnt+1)//2
        
        return ap_cnt
