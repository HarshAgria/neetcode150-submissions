class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;

        int l=0,r=height.size()-1;

        int ans=0;
        int lm=0,rm=0;
        
        while(l<r){
            if(height[l]<=height[r]){ //right side is good for moving left

                if(lm<=height[l]) lm=height[l];
                else ans+= lm-height[l];

                l++;     
            }
            else{
                if(rm<=height[r]) rm=height[r];
                else ans+= rm-height[r];

                r--;
            }
        }
        return ans;
    }
};
