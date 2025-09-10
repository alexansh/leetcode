class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bp = prices[0];
        int max=0;
        for(int i=1; i < prices.size(); i++){
            if(bp<prices[i]){
                max+= (prices[i]-bp);
            }
            bp = prices[i];
        }
        return{max};
}
};
