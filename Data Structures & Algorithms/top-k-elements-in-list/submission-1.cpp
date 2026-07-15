class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto i: nums){
            freq[i]++;
        }
       vector<pair<int,int>>freqvec(freq.begin(),freq.end());
        sort(freqvec.begin(),freqvec.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second>b.second;});
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(freqvec[i].first);
        }
        return ans;
    }
};
