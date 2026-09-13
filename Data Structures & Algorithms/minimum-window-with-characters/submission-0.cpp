class Solution {
public:
    string minWindow(string s, string t) {
        int minlength=INT_MAX;
        
        int sindex=-1;
        
        
        for(int i=0;i<s.length();i++){
            int cnt=0;
            unordered_map<char,int> countoft;
            for(char c:t){
            countoft[c]++;
        }
            for(int j=i;j<s.length();j++){
                if(countoft[s[j]]>0)cnt++;
                countoft[s[j]]--;

                if(cnt==t.length()){
                    if(j-i+1<minlength){
                        minlength=j-i+1;
                        sindex=i;
                    }
                    break;
                }
            }
        }
         if(sindex == -1)
            return "";
        return s.substr(sindex,minlength);
        
    }
};
