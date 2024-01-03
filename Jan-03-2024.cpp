class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int ans = 0;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = 0;
            for(auto &ch : bank[i])
            {
                if(ch == '1')
                    curr++;
            }
            ans += (curr*prev);
            if(curr != 0)
                prev = curr;
        }

        return ans;
    }
};