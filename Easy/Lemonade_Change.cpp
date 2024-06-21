class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        
        int n = b.size();
        int c5=0, c10=0;

        for(int i=0 ; i<n ; i++)
        {
            if(b[i] == 5)
            {
                c5++;
            }else if(b[i] == 10)
            {
                c10++;
                if(c5 == 0) return false;
                c5--;
            }else
            {
                if(c10 != 0 && c5 != 0)
                {
                    c10--;
                    c5--;
                }else if(c10 == 0 && c5 >= 3)
                {
                    c5 -= 3;
                }else return false;
            }
        }
        return true;
    }
};
