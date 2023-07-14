class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int d)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        m[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            int req = arr[i] - d;
            if (m[req])
                m[arr[i]] = max(m[arr[i]], m[req] + 1);
            else
                m[arr[i]] = 1;
        }

        int ans = 1;
        for (auto x : m)
            ans = max(ans, x.second);

        return ans;
    }
};