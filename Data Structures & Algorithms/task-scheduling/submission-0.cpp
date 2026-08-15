class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(char c:tasks){
            cnt[c-'A']++;
        }
        priority_queue<int>maxheap;
        for(int n:cnt){
            if(n>0){
                maxheap.push(n);
            }
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!maxheap.empty()|| ! q.empty()){
            time++;
            if(maxheap.empty()){
                time=q.front().second;
            }
            else{
                int temp=maxheap.top()-1;
                maxheap.pop();
                if(temp>0){
                     q.push({temp,time+n});
                }
            }
            if(!q.empty()&& q.front().second==time){
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
