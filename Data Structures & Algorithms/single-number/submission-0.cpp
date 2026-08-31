class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        // x^x=0 , x^0=x
        for(int i:nums){
            ans^=i;
        }
        return ans;
    }
};
