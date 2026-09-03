class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int k=s1.length();
        for(char& c : s1) c1[c-'a']++;
        for(int i=0;i<s2.size();i++){
            c2[s2[i]-'a']++;
            if(i>=k) c2[s2[i-k]-'a']--;
            if(c1==c2) return true; 
        }
        return false;
        
    }
};