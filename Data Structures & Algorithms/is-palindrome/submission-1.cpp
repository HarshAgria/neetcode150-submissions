class Solution {
public:
    bool isPalindrome(string s) {

        /*isalnum and tolower are important*/
        int length=s.length();
        int l=0,r=length-1;
        while(l<=r){
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;

            if(tolower(s[l])!=tolower(s[r])) return 0;
            l++;
            r--;
        }
        return 1;
    }
};
