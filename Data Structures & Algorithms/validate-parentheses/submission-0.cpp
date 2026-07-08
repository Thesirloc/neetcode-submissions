class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            switch (s[i]){
                case ')':
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false;
                    break;
                case '}':
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false;
                    break;
                case ']':
                    if(!st.empty() && st.top() == '[') st.pop();
                    else{
                        return false;
                    }
                    break;
                default:
                    st.push(s[i]);
                    break;
            }
        }
        if(!st.empty()){
            cout << "final " << st.top() << endl;
            return false;
        }
        return true;
    }
};
