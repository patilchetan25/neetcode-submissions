class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int l=0,res=0,maxf=0,n=s.size();
        for(int r=0;r<n;r++){
            count[s[r]]++;
            maxf=max(maxf,count[s[r]]);

            while((r-l+1)-maxf>k){
                count[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;  
    }
};
