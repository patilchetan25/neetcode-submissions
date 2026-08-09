class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0,minibuy=prices[0];
        for(int sell:prices){
            maxp=max(maxp,sell-minibuy);
            minibuy=min(sell,minibuy);
        }
        return maxp;
        
    }
};
