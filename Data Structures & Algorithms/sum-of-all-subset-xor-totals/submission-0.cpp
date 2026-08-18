class Solution {
private:
    int helper(const vector<int>&nums,int idx,int currxor){
        if(idx==nums.size()){
            return currxor;
        }
        int include=helper(nums,idx+1,currxor^nums[idx]);
        int exclude=helper(nums,idx+1,currxor);
        return include+exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};