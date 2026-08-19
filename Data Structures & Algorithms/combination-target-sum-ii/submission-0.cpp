class Solution {
public:
    void getallcombi(vector<int>& nums,int i,vector<int>&combi,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(combi);
        }
        for(int j=i;j<nums.size();j++){
            if(nums[j]>target) break;
            if(j>i && nums[j]==nums[j-1])continue;
            combi.push_back(nums[j]);
            getallcombi(nums,j+1,combi,ans,target-nums[j]);
            combi.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       vector<int>combi;
        vector<vector<int>>ans;
        getallcombi(nums,0,combi,ans,target);
        return ans;
    }
};
