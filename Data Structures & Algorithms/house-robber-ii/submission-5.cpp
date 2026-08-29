class Solution {
public:
    int solve(vector<int>&nums,vector<int>& dp,int p,int q){
        dp[p]=0;
        dp[p+1]=nums[p];

        for(int i=p+2;i<=q+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[q+1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,0);

        int a1=solve(nums,dp,0,n-2);
        int a2=solve(nums,dp,1,n-1);
        return max(a1,a2);
    }
};
