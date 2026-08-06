class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res=0;
        for(int x:nums){
            if(!mp[x]){
                mp[x]=mp[x-1]+mp[x+1]+1;
                mp[x-mp[x-1]]=mp[x];
                mp[x+mp[x+1]]=mp[x];
                res=max(res,mp[x]);
            }

        }
        return res;
        
    }
};
