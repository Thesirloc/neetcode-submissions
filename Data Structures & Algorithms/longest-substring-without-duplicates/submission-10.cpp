class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1) return 0;
        map<char, int> uniq;
        int maxSize = 1;
        for(int i=0;i<s.size();i++){
            if(uniq.find(s[i]) == uniq.end()){
                uniq[s[i]] = i;
                int setSize = uniq.size();
                maxSize = max(maxSize, setSize);
            }
            else{
                int idx = uniq[s[i]];
                for(auto it: uniq){
                    if(it.second < idx){
                        uniq.erase(it.first);
                    }
                }
                uniq[s[i]] = i;
                int setSize = uniq.size();
                maxSize = max(maxSize, setSize);
            }
        }
        return maxSize;
    }
};
