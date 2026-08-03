class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i:nums){
            m[i]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto i:m){
            bucket[i.second].push_back(i.first);
        }
        for(int i=bucket.size()-1;i>=0 ; i--){

            for(int i: bucket[i]){
                if(ans.size()==k) break;
                ans.push_back(i);
            }
        }
        return ans;
    }





};
