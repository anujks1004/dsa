class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int left = 0;
        int right = costs.size() - 1;
        while(left < candidates and left <= right)
        {
            pq.push({costs[left],left});
            if(left != right)
                pq.push({costs[right],right});
            left++;
            right--;

        }
        while(k > 0 and !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            // cout<<top.first<<" "<<top.second<<endl;
            sum += top.first;
            int idx = top.second;
            if(idx < left and left <= right)
            {
                pq.push({costs[left],left});
                left++;
            }

            else if(idx > right and left <= right)
            {
                pq.push({costs[right],right});
                right--;
            }
            k--;
        }

        return sum;


    }
};