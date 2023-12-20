class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int sum = INT_MAX;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            sum = min(sum, prices[i] + minPrice);
            minPrice = min(minPrice,prices[i]);
        }

        return sum > money ? money : (money - sum);
    }
};