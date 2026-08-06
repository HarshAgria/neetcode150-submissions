class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        int n=s.length();

        vector<bool> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                string x=s.substr(i,j-i+1);

                if(set.count(x) && dp[j+1]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};
