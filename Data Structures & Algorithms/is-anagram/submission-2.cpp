class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>m;
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(m.find(t[i]) == m.end()) return false;
            m[t[i]]--;
            if(m[t[i]]<0) return false;
        }
        return true;
    }
};
