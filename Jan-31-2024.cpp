class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(0);
        for(int i = 1; i < n; i++)
        {
            while(!st.empty() and temp[i] > temp[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};