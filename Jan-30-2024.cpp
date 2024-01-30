class Solution {
public:

    bool isOperator(string token)
    {
        return (token == "+") or (token == "*") or (token == "-") or (token == "/");
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto token : tokens)
        {
            if(isOperator(token))
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if(token == "+")
                    st.push(num1 + num2);
                else if(token == "-")
                    st.push(num1 - num2);
                else if(token == "*")
                    st.push(num1 * num2);
                else
                    st.push(num1 / num2);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};