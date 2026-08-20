class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else if(i==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(i=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if(i==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else return 0;
            
        }
        if(st.empty()) return true;
        return 0;
    }
};
