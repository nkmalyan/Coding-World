class Solution {
public:
    int maxProfit(vector<int>&  prices) {
        int minPrice =  prices[0];
        int  maxProfit = 0;
        
        for (int i = 1; i < (int)prices.size() ;  i++) {
            if (prices[i] < minPrice) {
               minPrice = prices[i];
            } 
            else {
               int profit = prices[i] - minPrice;
                maxProfit = std::max(maxProfit, profit);
            }
        }
        return  maxProfit;
    }
};
