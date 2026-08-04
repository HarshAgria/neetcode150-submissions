class Solution {
public:
    vector<string> ans;

    void traverse(string s,unordered_map<string,priority_queue<string,vector<string>, greater<string>>> &m){

        while(!m[s].empty()){
            string x=m[s].top();
            m[s].pop();
            traverse(x,m);
        }
        ans.push_back(s);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets){
        // Appears simple but actually not
        /*
        think of like graph in which we need to traverse all edges
        in lexilogically accending order.
        the root node is 'JFK' and then we go on

        the main idea is thinking of using priority queue in making adjacency list
        such that unordered_map<string,priority_queue<string,vector<string>, greater<string>>>
        */

        unordered_map<string,priority_queue<string,vector<string>, greater<string>>> m;
        for(auto i:tickets){
            m[i[0]].push(i[1]);
        }

        traverse("JFK",m);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
