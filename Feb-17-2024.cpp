class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        for(int i = 0; i < n - 1; i++)
        {
            if(heights[i+1] <= heights[i])
                continue;
            
            int diff = heights[i+1] - heights[i];
            if(bricks >= diff)
            {
                pq.push(diff);
                bricks -= diff;
            }

            else if(ladders)
            {
                if(!pq.empty() and pq.top() >= diff)
                {
                    int top = pq.top();
                    pq.pop();
                    pq.push(diff);
                    bricks += top;
                    bricks -= diff;
                }
                ladders--;
            }
            else
                return i;
        }
        return n - 1;
    }
};