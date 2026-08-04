class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int>ans(n,1);
        int f=1;
        for(int i=0;i<n;i++){
            ans[i]=f;
            f=f*nums[i];
        }
        int l=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*l;
            l=l*nums[i];
        }
        return ans;

    }
};
