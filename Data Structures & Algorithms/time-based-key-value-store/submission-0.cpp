class TimeMap {
    unordered_map<string,vector<pair<int,string>>>keystore;
public:
    TimeMap(){
    }
    
    void set(string key, string value, int timestamp) {
        keystore[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& values=keystore[key];
        int l=0,r=values.size()-1;
        string res="";
        while(l<=r){
            int m=l+ (r-l)/2;
            if(values[m].first<=timestamp){
                res=values[m].second;
                l++;
            }
            else r--;
        }
        return res;
    }
};
