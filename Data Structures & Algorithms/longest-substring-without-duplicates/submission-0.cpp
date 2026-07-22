class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>mp(256,-1);
       int l=0,r=0,n=s.size();
       int maxlen=0;
       while(r<n){
        int length=1;
        if(mp[s[r]]!=-1){
            if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
        }
        length=r-l+1;
        maxlen=max(length,maxlen);
        mp[s[r]]=r;
        r++;
       }
       return maxlen;
    }
};
