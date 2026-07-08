class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>m(26,0);
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            m[int(s[i]) - int('a')]++;
        }
        for(int i=0;i<t.size();i++){
            m[int(t[i]) - int('a')]--;
        }
        for(int i=0;i<m.size();i++){
            if(m[i] != 0) return false;
        }
        return true;
    }
};
