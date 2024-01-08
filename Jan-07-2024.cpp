class Solution {
public:

    #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        map<ll,ll> dp[n+1];
        ll res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll temp=1LL*nums[i]-1LL*nums[j];  //using long long here to avoid overflow
                
                if(dp[j].count(temp))
                {
                    res+=dp[j][temp];
                    dp[i][temp]+=dp[j][temp];    //using dp[i][temp] to store no. of subsequence with common diff of diff,till ith index
                }
                
                dp[i][temp]+=1;
            }
        }
        return res;
    }
};