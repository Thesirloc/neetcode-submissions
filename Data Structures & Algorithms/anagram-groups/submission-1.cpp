class Solution {
public:

    bool isAnagram(string a, string b){
        if(a.size() != b.size()) return false;
        vector<int> comp(26,0);
        for(int i=0;i<a.size();i++){
            comp[a[i]-'a']++;
            comp[b[i]-'a']--;
        }
        for(int i=0;i<comp.size();i++){
            if(comp[i] != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a map same length as strs
        int n = strs.size();
        map<vector<int>,vector<string>> m;
        vector<int>track(n);
        //iterate through each string, if index is 1 skip it, if index is 0 create hashmap and check for anagrams
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            vector<int> ind(26);
            for(int j=0;j<strs[i].size();j++){
                ind[strs[i][j]-'a']++;
            }
            m[ind].push_back(strs[i]);
        }
        for(auto it: m){
            result.push_back(it.second);
        }
        return result;
    }
};
