class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return ispalindrome(s.substr(0,l)+s.substr(l+1)) || ispalindrome(s.substr(0,r)+s.substr(r+1));
            
            }
            l++;r--;
        }
        return true;
    }
     private:
    bool ispalindrome(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};
   