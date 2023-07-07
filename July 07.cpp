class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans=0;
        int left=0,right=0;
        int count=0;
        while(right<key.size())
        {
            if(key[right]=='T')
                count++;
            while(count>k)
            {
                if(key[left]=='T')
                    count--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        left=0,right=0,count=0;
        while(right<key.size())
        {
            if(key[right]=='F')
                count++;
            while(count>k)
            {
                if(key[left]=='F')
                    count--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};