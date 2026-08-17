class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={};
        int n=nums.size();
        for(int i=0;i<=n-3;i++){
            // skip duplicate i
            if(i>0 && nums[i]==nums[i-1]) continue;
            int t=nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                int s=(nums[j]+nums[k]);
                if(s==-t){
                    ans.push_back({t,nums[j],nums[k]});
                    j++;
                    k--;
                    //skip duplicate j and k
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                } 


                else if(s>-t){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }

};
