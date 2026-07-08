class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i=0;i<strs.size();i++){
            encoded += to_string(strs[i].size());
            encoded += ("(" + strs[i]);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string templen = "";
        string tempstring = "";
        int tempstringlen = 0;
        bool counting = false;
        for(int i=0;i<s.size();i++){
            if(counting == true){
                tempstring += s[i];
                if(tempstring.size() == tempstringlen){
                    counting = false;
                    decoded.push_back(tempstring);
                    tempstring = "";
                    tempstringlen = 0;
                }
            }
            else if(s[i] != '(') templen += s[i];
            else{
                tempstringlen = stoi(templen);
                if(tempstringlen == 0){
                    decoded.push_back("");
                    continue;
                }
                counting = true;
                templen = "";
            }

        }
        return decoded;
    }
};
