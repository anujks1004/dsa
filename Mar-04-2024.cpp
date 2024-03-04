class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)
            return 0;
        
        sort(tokens.begin(),tokens.end());
        int low=0;
        int high=tokens.size()-1;
        int max_score=0;
        int score=0;
        if(tokens[low]>power)
            return 0;
        while(low<=high)
        {
            if(tokens[low]<=power)
            {
                power-=tokens[low];
                score++;
                max_score=max(score,max_score);
                low++;
            }
            else if(score>0)
            {
                power+=tokens[high];
                score--;
                high--;
            }
        }
        return max_score;
    }
};