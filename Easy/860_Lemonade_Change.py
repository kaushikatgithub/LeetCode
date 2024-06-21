class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        
        c5, c10 = 0, 0
        
        for b in bills:
    
            if b == 5:
                c5 += 1
            elif b == 10:
                c10 += 1
                if c5 == 0:
                    return False
                c5 -= 1
            else:
                if c10 != 0 and c5 != 0:
                    c10 -= 1
                    c5 -= 1
                elif c10 == 0 and c5 >= 3:
                    c5 -= 3
                else:
                    return False
            
        return True
