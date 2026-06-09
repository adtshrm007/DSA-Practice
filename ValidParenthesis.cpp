class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0||s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else if(s[i]=='}'){
                    if(st.top()=='{'){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};