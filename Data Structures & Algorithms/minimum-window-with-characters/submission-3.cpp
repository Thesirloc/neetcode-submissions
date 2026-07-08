class Solution {
public:
    bool compareArrays(vector<int> &a, vector<int> &b){
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] - b[i] < 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        if(n<t.size()) return "";
        vector<int>s1(256), t1(256);
        for(int i=0;i<t.size();i++){
            t1[t[i]-'A']++;
            s1[s[i]-'A']++;
        }
        if(s1==t1){
            string ans = "";
            for(int m=0;m<t.size();m++){
                ans += s[m];
            }
            return ans;
        }
        int substringLow = 0;
        int substringHigh = 0;
        int minLength = 1001;
        int globalMinLength = 1001;
        int i=0,j=t.size();
        while(j<n+1){
            bool contains = compareArrays(s1,t1);
            if(contains){
                minLength = j-i;
                if(globalMinLength > minLength){
                    globalMinLength = min(minLength, globalMinLength);
                    cout<< "minLength = " << minLength << " " << "globalminlength = " << globalMinLength << endl;
                    substringLow = i;
                    substringHigh = j;
                }
                s1[s[i]-'A']--;
                i++;
            }
            else{
                if(j<n){
                    s1[s[j]-'A']++;
                    j++;
                }
                else break;
            }
        }
        // if(compareArrays(s1,t1)){
        //     minLength = j-i;
        //     if(globalMinLength > minLength){
        //         globalMinLength = min(minLength, globalMinLength);
        //         cout<< "minLength = " << minLength << " " << "globalminlength = " << globalMinLength << endl;
        //         substringLow = i;
        //         substringHigh = j;
        //     }
        // }
        if(globalMinLength > s.size()) return "";
        string finalsubString = "";
        for(int k = substringLow;k<substringHigh;k++){
            finalsubString += s[k];
        }
        return finalsubString;
    }
};
