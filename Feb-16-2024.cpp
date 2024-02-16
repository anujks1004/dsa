class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>freq;
        for(int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto num : freq)
            pq.push(num.second);
        while(!pq.empty() and k--)
        {
            int top = pq.top();
            pq.pop();
            if(--top)
                pq.push(top);
        }

        return pq.size();
    }
};