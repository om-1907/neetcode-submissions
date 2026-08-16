class Twitter {
private:
    int time;
    unordered_map<int,unordered_set<int>>followmap;
    unordered_map<int,vector<pair<int,int>>>tweetmap;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>>maxheap;
        unordered_set<int>userfeed=followmap[userId];
        userfeed.insert(userId);
        for(int followid:userfeed){
            if(tweetmap.find(followid)!=tweetmap.end()&&!tweetmap.empty()){
                int lastidx=tweetmap[followid].size()-1;
                auto [time,tweetid]=tweetmap[followid][lastidx];
                maxheap.push({time,tweetid,followid,lastidx-1});
            }
        }
        vector<int>feed;
        while(!maxheap.empty()&&feed.size()<10){
            auto[time,tweetid,followid,nextidx]=maxheap.top();
            maxheap.pop();
            feed.push_back(tweetid);
            if(nextidx>=0){
                auto[prevtime,prevtweetid]=tweetmap[followid][nextidx];
                maxheap.push({prevtime,prevtweetid,followid,nextidx-1});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followmap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
