class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;
        for(auto num:stones){
            maxheap.push(num);
        }
        while(maxheap.size()>1){
            int fst=maxheap.top();
            maxheap.pop();
            int snd=maxheap.top();
            maxheap.pop();
            if(fst!=snd){
                maxheap.push(abs(fst-snd));
            }
        }
        return maxheap.empty()? 0:maxheap.top();
    }
};
