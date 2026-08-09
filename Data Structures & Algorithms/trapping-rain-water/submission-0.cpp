class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,leftmax=height[l],rightmax=height[r],res=0;
        while(l<r){
            if(leftmax<rightmax){
               l++;
               leftmax=max(leftmax,height[l]);
               res=res+leftmax-height[l];
            }
            else{
                r--;
                rightmax=max(rightmax,height[r]);
                res=res+rightmax-height[r];
            }
        }
        return res;
        
    }
};
