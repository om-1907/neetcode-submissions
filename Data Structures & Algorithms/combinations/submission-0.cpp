class Solution {
public:
    void backtrack(int start,int n,int k,vector<int>& curr,vector<vector<int>> & ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        int maxstart=n-(k-curr.size())+1;
        for(int i=start;i<=maxstart;i++){
            curr.push_back(i);
            backtrack(i+1,n,k,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        vector<vector<int>>ans;
        backtrack(1,n,k,curr,ans);
        return ans;
    }
};