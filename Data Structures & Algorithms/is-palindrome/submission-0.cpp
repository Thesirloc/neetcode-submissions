class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
            if((int(s[i]) <= 57 && int(s[i]) >= 48) || (int(s[i]) <= 90 && int(s[i]) >= 65) || (int(s[i]) <= 122 && int(s[i]) >= 97)) a.push_back(s[i]);
        }
        int i=0;
        int j = a.size()-1;
        while(i<j){
            if(int(a[i])==int(a[j])){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
