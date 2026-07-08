class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        // for(int i=0;i<n;i++){
        //     map<char,int>m;
        //     int maxEl = 0;
            
        //     for(int j=i;j<n;j++){
        //         m[s[j]]++;
        //         maxEl = max(maxEl, m[s[j]]);
        //         int replacements = j-i+1 - maxEl;
        //         if(replacements <= k){
        //             maxLen = max(maxLen, j-i+1);
        //         }
        //         else break;
        //     }
        //     m.clear();
        // }
        // return maxLen;

        int i=0,j=0;
        map<char,int>m;
        int flag=1;
        while(j<n && i<=j){
            if(flag==1) m[s[j]]++;
            int maxEl=0;
            for(auto it: m){
                maxEl = max(maxEl, it.second);
            }
            int replacements = j-i+1 - maxEl;
            if(replacements <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
                flag=1;
            }
            else{
                m[s[i]]--;
                i++;
                flag=0;
            }
        }
        return maxLen;
    }
};
