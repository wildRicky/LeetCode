//贪心算法，只要有利润就卖出，成本低就买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size(),profit=0;
        for(int i=1;i<size;++i)
        {
            if(prices[i]>prices[i-1])
            {
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
