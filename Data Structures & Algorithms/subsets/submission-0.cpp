class Solution {
public:
    void getall(vector<int>& nums,vector<int>&ans, int i, vector<vector<int>>& allsubsets)
    {
       if(i==nums.size()){
        allsubsets.push_back({ans});
        return;
       }

       ans.push_back(nums[i]);
       getall(nums,ans,i+1,allsubsets);

       ans.pop_back();
       getall(nums,ans,i+1,allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allsubsets;
        vector<int>ans;
        getall(nums,ans,0,allsubsets);
        return allsubsets;
    }
};
