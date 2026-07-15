class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>freq;
       for(int i:nums){
            freq[i]++;
       }
        int maxelement=-1,maxfreq=0;
        for(auto j:freq){
            if(j.second>maxfreq){
                maxfreq=j.second;
                maxelement=j.first;
            }
        }
        return maxelement;
    }
};