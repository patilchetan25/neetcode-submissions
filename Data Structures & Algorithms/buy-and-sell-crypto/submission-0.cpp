class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,profit=0,maxp=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                profit=prices[r]-prices[l];
                maxp=max(maxp,profit);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxp;
        
    }
};
