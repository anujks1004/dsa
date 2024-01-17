class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>freq;
        for(int i = 0; i < arr.size(); i++)
        {
            int ct = 1;
            while(i + 1 < arr.size() and arr[i] == arr[i+1])
            {
                ct++;
                i++;
            }
            freq.push_back(ct);
        }

        sort(freq.begin(),freq.end());
        for(int i = 0; i < freq.size() - 1; i++)
        {
            if(freq[i] == freq[i+1])
                return false;
        }

        return true;
    }
};