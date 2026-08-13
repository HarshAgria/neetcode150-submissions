class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Multi-source BFS problem
        int fresh=0;
        int time=-1; // before start
        queue<pair<int,int>> q;
        int r=grid.size(), c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) fresh+=1;

                if(grid[i][j]==2) q.push({i,j});
            }
        }

        vector<pair<int,int>> D={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int qs=q.size();
            while(qs--){
                pair<int,int> index=q.front();
                q.pop();

                for(auto d:D){
                    int i=index.first+d.first;
                    int j=index.second+d.second;

                    if((i>=0 && i<r) && (j>=0 && j<c) && grid[i][j]==1){
                        grid[i][j]=2;
                        fresh--;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }
        if(fresh!=0) return -1;
        if(time<0) return 0;
        return time;
    }
};
