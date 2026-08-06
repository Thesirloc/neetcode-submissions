class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        stack<pair<int,int>> s;
        float prevt = 1.0*(target - v[n-1].first)/(v[n-1].second);
        s.push(v[n-1]);
        int fleets = 0;
        if(n<=1) return 1;
        for(int i=n-2;i>=0;i--){
            float currt = 1.0*(target - v[i].first)/(v[i].second);
            if(currt > prevt){
                while(!s.empty()) s.pop();
                fleets++;
                s.push(v[i]);
                prevt = currt;
            }
            else{
                s.push(v[i]);
            }
        }
        if(!s.empty()){
            fleets++;
        }
        return fleets;
    }
};
