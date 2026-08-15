class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n =temperatures.size();
        stack <int> s;
        vector<int> res(n,0);
        for (int i=0;i<n;i++){
            int curr=temperatures[i];
            while(!s.empty()&& temperatures[s.top()]<curr){
                int nge=s.top();
                s.pop();
                res[nge]=i-nge;
            }
            s.push(i);
        }
        return res;
        
    }
};
