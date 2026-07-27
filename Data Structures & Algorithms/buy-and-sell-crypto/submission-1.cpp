class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, sell = 1, maxProfit = 0, profit = 0;

        while(sell < n){
            if(prices[sell] > prices[buy]){
                profit = prices[sell]-prices[buy];
                maxProfit = max(maxProfit, profit);
            }else{
                buy = sell;
            }

            sell++;
        }
        return maxProfit;   
    }
};