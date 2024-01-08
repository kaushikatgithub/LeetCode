class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3) {
            return 0;
        }

        int count_triplets = 0, count_aps = 0;
        for(int i = 0 ; i < n-2 ; i++) {
            if(nums[i+1] - nums[i] == nums[i+2] - nums[i+1]) {
                count_triplets++;
            }else {
                count_aps += (count_triplets)*(count_triplets+1)/2;
                count_triplets = 0;
            }
        }

        if(count_triplets){
            count_aps += (count_triplets)*(count_triplets+1)/2;
            count_triplets = 0;
        }
        return count_aps;
    }
};
