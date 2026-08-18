class Solution {
public:
    set<vector<int>>mp;
    void getallcombi(vector<int>& nums,int i,vector<int>&combi,vector<vector<int>>& ans,int target){
        if(i==nums.size() || target<0){
            return;
        }
        if(target==0){
            if(mp.find(combi)==mp.end()){
                ans.push_back({combi});
                mp.insert({combi});
            }
        }
        combi.push_back(nums[i]);
        getallcombi(nums,i+1,combi,ans,target-nums[i]);
        getallcombi(nums,i,combi,ans,target-nums[i]);
        combi.pop_back();
        getallcombi(nums,i+1,combi,ans,target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>combi;
        vector<vector<int>>ans;
        getallcombi(nums,0,combi,ans,target);
        return ans;
    }
};
