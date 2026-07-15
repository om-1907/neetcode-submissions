class Solution {
public:
    bool isPalindrome(string s) {
        string p="";
        for(char c:s){
            if(isalnum(c)){
                p+=tolower(c);
            }
        }
        return p==string(p.rbegin(),p.rend());
    }
};
