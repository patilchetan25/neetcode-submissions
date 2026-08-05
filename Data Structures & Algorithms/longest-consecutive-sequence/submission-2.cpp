class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(),nums.end());
        int longest=0;
        for(int x : uset){
            if(uset.find(x-1)==uset.end()){
                int length=1;
                while(uset.find(x+length)!=uset.end()){
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};
