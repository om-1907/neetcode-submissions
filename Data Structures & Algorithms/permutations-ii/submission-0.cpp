class Solution {
public:
    void backtrack(int start,vector<int> & nums, vector<vector<int>>&res){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int>seen;
        for(int i=start;i< nums.size();i++){
            if(seen.count(nums[i]))continue;
            seen.insert(nums[i]);
            swap(nums[start],nums[i]);
            backtrack(start+1,nums,res);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        backtrack(0,nums,res);
        return res;
    }
};