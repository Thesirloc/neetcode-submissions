class TimeMap {
public:
    map<string, vector<pair<int,string>>> m;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) != m.end()){
            int lo = 0,hi = m[key].size()-1;
            string ans;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(m[key][mid].first <= timestamp){
                    ans = m[key][mid].second;
                    lo = mid+1;
                }
                else{
                    hi = mid - 1;
                }
            }
            return ans;
        }
        else return "";
    }
};
