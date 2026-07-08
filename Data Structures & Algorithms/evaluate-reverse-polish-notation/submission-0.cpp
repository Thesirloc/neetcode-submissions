class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        long eval = 0;
        stack<long> st;
        for(int i=0;i<n;i++){
            if(tokens[i] == "+"){
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                eval = b + a;
                st.push(eval);
            }
            else if(tokens[i] == "-"){
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                eval = b - a;
                st.push(eval);
            }
            else if(tokens[i] == "*"){
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                eval = b * a;
                st.push(eval);
            }
            else if(tokens[i] == "/"){
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                eval = b / a;
                st.push(eval);
            }
            else{
                st.push(stol(tokens[i]));
            }
        }
        return (int)st.top();
    }
};
