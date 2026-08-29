class Solution {
public:
    int solve(vector<int>& nums,int p,int q){
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1,0);
        dp[p]=0;
        dp[p+1]=nums[p];

        for(int i=p+2;i<=q+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[q+1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        int a1=solve(nums,0,n-2);
        int a2=solve(nums,1,n-1);
        return max(a1,a2);
    }
};
