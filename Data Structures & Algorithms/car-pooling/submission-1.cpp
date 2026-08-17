class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       sort(trips.begin(),trips.end(),[](const vector<int>&a,const vector<int>&b)
       {return a[1]<b[1];});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        int curr=0;
        for(const auto trip:trips){
            int numpass=trip[0];
            int from=trip[1];
            int to=trip[2];
            while(!minheap.empty()&&minheap.top().first<=from){
                curr-=minheap.top().second;
                minheap.pop();
            }
            curr+=numpass;
            minheap.push({to,numpass});
            if(curr>capacity)return false;
        }
        return true;
    }
};