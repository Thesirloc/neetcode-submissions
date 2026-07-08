class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a1(26), a2(26);
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        for(int k=0;k<n1;k++){
            a1[s1[k] - 'a']++;
            a2[s2[k] - 'a']++;
        }
        if(a1==a2) return true;
        int i=0,j=n1;
        while(j<n2){
            a2[s2[i] - 'a']--;
            i++;
            a2[s2[j] - 'a']++;
            j++;
            if(a1==a2) return true;
        }
        return false;
    }
};
