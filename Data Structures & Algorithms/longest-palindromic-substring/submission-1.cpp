class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int anslen=1;
        int start=0;
        for(int len=2;len<=n;len++){
            int i=0;
            while(i<n-len+1){
                int j=i+len-1;
                if(s[i]==s[j] && (len == 2 || dp[i+1][j-1])){
                    dp[i][j]=1; 
                    if(len>anslen){
                anslen=len;
                start=i;
            }
                } 
            
            
            i++;
            }
        }



        return s.substr(start,anslen);

    }
};
