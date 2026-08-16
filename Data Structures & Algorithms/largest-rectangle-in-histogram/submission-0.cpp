class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<int> s;
        for(int i=0;i<=heights.size();i++){
            while(!s.empty()&&(i==heights.size() || heights[s.top()]>=heights[i])){
                int h=heights[s.top()];
                s.pop();
                int left=s.empty()?-1:s.top();
                int w=i-left-1;
                int newarea=h*w;
                area=max(area,newarea);
            }
            s.push(i);
        }
        return area;
        

    }
};
