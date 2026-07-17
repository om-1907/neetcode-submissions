class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,zerocnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }
            else zerocnt++;
        }
        if(zerocnt>1){
            return vector<int>(nums.size(),0);
        }
        vector<int>op(nums.size());
        for(int i=0;i<nums.size();i++){
            if(zerocnt>0){
                op[i]=(nums[i]==0)?prod:0;
            }
            else{
                op[i]=prod/nums[i];
            }
        }
        return op;
    }
};
