class Solution {
public:

    string encode(vector<string>& strs) {
// strs = ["Hello","World"]
// 5#Hello5#World
        string encoded="";
        for(auto i:strs){
            int len=i.length();
            encoded+=to_string(len)+"#"+i;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i=0,j=0;
        while(i<s.length()){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string temp="";
            temp=s.substr(j+1,len);
               
            decoded.push_back(temp);
            i=j+len+1;
        }
        return decoded;
    }
};
