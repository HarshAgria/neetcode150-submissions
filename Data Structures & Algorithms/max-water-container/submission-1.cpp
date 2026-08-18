class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int area=0;
        while(l<r){
            int len=r-l;
            int b=min(heights[l],heights[r]);
            int a=len*b;

            area=max(area,a);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return area;
    }
};
