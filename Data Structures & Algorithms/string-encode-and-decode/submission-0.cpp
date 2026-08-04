class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        for(string& s: strs){
            sizes.push_back(s.size());
        }
        string res;
        for(int x : sizes){
            res.append(to_string(x));
            res.push_back(',');
        }
        res.push_back('#');
        for(string& s: strs){
            res.append(s);
        }
        return res;

    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int>sizes;
        vector<string>res;
        int i=0;
        while(s[i]!='#'){
            int j=i;
            while(s[j]!=','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            i=j+1;
        }
        i++;

        for(int x:sizes){
            res.push_back(s.substr(i,x));
                i=i+x;
        }
        return res;
        


        

    }
};
