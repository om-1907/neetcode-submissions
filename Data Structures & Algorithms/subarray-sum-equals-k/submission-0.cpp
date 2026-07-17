class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        int res=0;
        count[0]=1;
        int prefix=0;
        for(auto i:nums){
            prefix+=i;
            if(count.find(prefix-k)!=count.end()){
                res+=count[prefix-k];
            }
                count[prefix]++;
        }
        return res;
    }
};