class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxSub = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            map<char,int>m;
            int maxEl = 0;
            
            for(int j=i;j<n;j++){
                m[s[j]]++;
                maxEl = max(maxEl, m[s[j]]);
                int replacements = j-i+1 - maxEl;
                if(replacements <= k){
                    maxLen = max(maxLen, j-i+1);
                }
                else break;
            }
            m.clear();
        }
        return maxLen;
    }
};
