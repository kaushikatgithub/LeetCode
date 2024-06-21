class Solution:
    def twoSum(self, a: List[int], t: int) -> List[int]:
        
        i, j = 0, len(a)-1
        while i < j:
            sum = a[i] + a[j]
            if sum == t:
                return [i+1, j+1]
            elif sum < t:
                i += 1
            else:
                j -= 1
        return [-1, -1]
