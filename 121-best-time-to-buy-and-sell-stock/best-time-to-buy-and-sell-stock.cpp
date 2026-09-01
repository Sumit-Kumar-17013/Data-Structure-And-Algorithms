class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int MaxProfit = 0;

        for(int price : prices)
        {
            if(price < minprice)
            {
                minprice = price;
            }
            if(price - minprice > MaxProfit)
            {
                MaxProfit = price - minprice;
            }

        }
        return MaxProfit;
        
    }
};