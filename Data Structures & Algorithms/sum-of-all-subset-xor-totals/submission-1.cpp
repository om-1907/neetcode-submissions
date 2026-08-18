class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalxor=0;
        for(auto num:nums){
            totalxor |=num;
        }
        return totalxor<<(nums.size()-1);
    }
};