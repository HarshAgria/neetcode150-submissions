class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());

        for(int i:nums){
            if(s.count(i-1)) continue;

            int start=i;
            int l=0;

            while(s.count(start)){
                start++;
                l++;
            }
            ans=max(ans,l);
        }
        return ans;
    }
};
