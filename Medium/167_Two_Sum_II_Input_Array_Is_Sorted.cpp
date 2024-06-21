class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int i=0, j=a.size()-1;
        while(i < j)
        {
            int sum = a[i] + a[j];
            if(sum == t)
            {
                return {i+1, j+1};
            }else if(sum < t)
            {
                i++;
            }else {
                j--;
            }
        }
        return {-1, -1};
    }
};
