class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // For each i from [1, n], find j such that i < j <= n and prices[j] - prices[i] is maximum
        // So we reverse the vector and iterate with i. To maximize prices[j] - prices[i], find max(prices[j]) 
        // for all i < j <= n and subtract prices[i] from it. If ans < this max value, set ans to this value. 
        reverse(prices.begin(), prices.end());
        int ans = 0, mx = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            ans = max(ans, mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        
        // Return the answer.
        return ans;
    }
};