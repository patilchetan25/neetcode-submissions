class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        vector<pair<int,int>>res;
        for(auto& pair: mp){
            res.push_back({pair.second,pair.first});
        }
        sort(res.rbegin(),res.rend());
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(res[i].second);        
        }
        return result;
    }
        
};
