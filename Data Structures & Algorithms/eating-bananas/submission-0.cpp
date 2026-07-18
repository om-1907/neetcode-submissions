class Solution {
public:
    int totalhrs(vector<int> piles,int h){
        int totalH=0;
        for(int i=0;i<piles.size();i++){
            totalH+=ceil((double)piles[i]/(double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            int ans=totalhrs(piles,mid);
            if(ans<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};
