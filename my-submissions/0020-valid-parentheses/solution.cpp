class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(char c:s){
            if(c == '(' || c== '{' || c== '['){
                st.push_back(c);
            }
            else{
                if (st.empty()){
                    return false;
                }
                char top = st.back();
                st.pop_back();
                if(c==')' && top != '(' || c=='}' && top != '{' || c==']' && top != '['){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
