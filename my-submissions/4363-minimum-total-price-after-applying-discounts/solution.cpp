class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        
        double total = 0.0;
        int n = prices.size();
        int m = discounts.size();
        int limit = min(n, m);
        
        for (int i = 0; i < limit; i++) {
            total += (double)prices[i] * (100 - discounts[i]) / 100.0;
        }
        
        for (int i = limit; i < n; i++) {
            total += prices[i];
        }
        
        return total;
    }
};
