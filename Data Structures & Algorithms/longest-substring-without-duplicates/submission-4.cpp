class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        queue<char> q;
        set<char> unique;
        int ans = n == 0 ? 0 : 1;
        for(int i=0;i<n;i++){
            if(unique.find(s[i]) != unique.end()){
                int si = q.size();
                ans = max(ans, si);
                while(q.front() != s[i]){
                    unique.erase(q.front());
                    q.pop();
                }
                unique.erase(q.front());
                q.pop();

            }
            q.push(s[i]);
            unique.insert(s[i]);
        }
        int siz = q.size();
        ans = max(ans,siz);
        return ans;
    }
};
