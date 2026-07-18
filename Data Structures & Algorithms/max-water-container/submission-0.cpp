class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low=0,high=heights.size()-1;
        int maxi=0;
        while(low<high){
            int diff=high-low;    
            maxi=max(diff*min(heights[low],heights[high]),maxi);
            if(heights[low]<heights[high]){
                low++;
            }
            else if(heights[low]>heights[high]){
                high--;
            }
            else{
                low++;
            }
        }
        return maxi;
    }
};
