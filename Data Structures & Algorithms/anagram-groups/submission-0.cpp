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
        //create a index array same length as strs
        int n = strs.size();
        vector<int> ind(n,0);
        
        //iterate through each string, if index is 1 skip it, if index is 0 create hashmap and check for anagrams
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(ind[i] == 0){
                ind[i] = 1;
                vector<string> anagramListFori;
                anagramListFori.push_back(strs[i]);
                for(int j=i+1;j<n;j++){
                    if(ind[j] ==0){
                        if (isAnagram(strs[i],strs[j])){
                            anagramListFori.push_back(strs[j]);
                            ind[j]=1;
                        }
                    }
                }
                result.push_back(anagramListFori);
            }
        }
        return result;
    }
};
