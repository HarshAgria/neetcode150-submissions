class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int ans=0;
        while(l<r){
            int len=r-l;
            int b=min(heights[l],heights[r]);

            int area=len*b;
            ans=max(ans,area);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
