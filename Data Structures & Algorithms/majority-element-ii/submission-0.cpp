class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(auto x:nums){
            freq[x]++;
        }
        vector<int>res;
        for(auto &i:freq){
            if(i.second>floor(n/3)){
                res.push_back(i.first);
            }
        }
        return res;
    }
};