class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char &it : s){
            if(it == '('){
                st.push(')');
            }
            else if(it == '{'){
                st.push('}');
            }
            else if(it == '['){
                st.push(']');
            }
            else if(st.empty() || st.top() != it){
                return false;
            }else st.pop();

        }
        return st.empty();
    }
};