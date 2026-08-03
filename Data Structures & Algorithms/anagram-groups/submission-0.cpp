class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(auto s:strs){
            string orig=s;
            sort(s.begin(),s.end());
            m[s].push_back(orig);
        }
        for(auto &i:m){
            ans.push_back(i.second);
        }
        return ans;

    }
};
