#include<map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])==1) return true;

            else mp.insert({nums[i],i});
        }
        return false;
    
        
    }
};