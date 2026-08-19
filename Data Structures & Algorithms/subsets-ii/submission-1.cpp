class Solution {
public:
    void subsets(vector<int>& nums,vector<vector<int>>&res,vector<int>&subset,int start){
        res.push_back(subset);
        for(int i=start;i<nums.size();i++){
            if(start<i && nums[i]==nums[i-1])continue;
            subset.push_back(nums[i]);
            subsets(nums,res,subset,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        subsets(nums,res,subset,0);
        return res;
    }
};
