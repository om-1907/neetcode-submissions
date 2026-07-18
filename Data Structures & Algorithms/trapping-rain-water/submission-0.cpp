class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int res=0;
        int leftmax=height[l],rightmax=height[r];
        while(l<r){
            if(leftmax<rightmax){
                l++;
                leftmax=max(height[l],leftmax);
                res+=leftmax-height[l];
            }
            else{
                r--;
                rightmax=max(height[r],rightmax);
                res+=rightmax-height[r];
            }
        }
        return res;
    }
};
