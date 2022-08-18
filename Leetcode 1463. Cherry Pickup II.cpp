// recursive 
```
class Solution {
public:
    int solve(int i,int j1,int j2,int col,int row,vector<vector<int>>& grid){
        if(j1<0 || j2<0|| j1>=col|| j2>=col)
            return -1e8;
        if(i==row-1){
           if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        // explore all the paths
        int maxi=-1e8;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value=0;
                if(j1==j2)
                    value=grid[i][j1];
                else
                    value=grid[i][j1]+grid[i][j2];
                value+= solve(i+1,j1+dj1,j2+dj2,col,row,grid);
                maxi=max(maxi,value);
            
            }
        }
        return maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        return solve(0,0,col-1,col,row,grid);
    }
};
```

// memoization 
```
class Solution {
public:
    int solve(int i,int j1,int j2,int col,int row,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0|| j1>=col|| j2>=col)
            return -1e8;
        if(i==row-1){
           if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!= -1)
            return dp[i][j1][j2];
        // explore all the paths
        int maxi=-1e8;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value=0;
                if(j1==j2)
                    value=grid[i][j1];
                else
                    value=grid[i][j1]+grid[i][j2];
                value+= solve(i+1,j1+dj1,j2+dj2,col,row,grid,dp);
                maxi=max(maxi,value);
            
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        //dp[r][c][c]
        vector<vector<vector<int>>> dp(row,vector<vector<int>> (col,vector<int>(col,-1)));
        return solve(0,0,col-1,col,row,grid,dp);
    }
};
```
// tabulatiopn 
```
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        //dp[r][c][c]
        vector<vector<vector<int>>> dp(row,vector<vector<int>> (col,vector<int>(col,-1)));
        for(int j1=0;j1<col;j1++){
           for(int j2=0;j2<col;j2++){
                if(j1==j2)
                    dp[row-1][j1][j2]=grid[row-1][j1];
               else
                   dp[row-1][j1][j2]=grid[row-1][j1] +grid[row-1][j2];
            } 
        }
        
        for(int i=row-2;i>=0;i--){
            for(int j1=0;j1<col;j1++){
               for(int j2=0;j2<col;j2++){
                   int maxi=-1e8;
                    for(int dj1=-1;dj1<=+1;dj1++){
                        for(int dj2=-1;dj2<=+1;dj2++){
                            int value=0;
                            if(j1==j2)
                                value=grid[i][j1];
                            else
                                value=grid[i][j1]+grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<col && j2+dj2>=0 && j2+dj2<col)
                                value+= dp[i+1][j1+dj1][j2+dj2];
                            maxi=max(maxi,value);
                        }
                    }
                   dp[i][j1][j2]=maxi;
                
                } 
            }
        }
        return dp[0][0][col-1];
    }
};
```
// sapce optemized
```
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
            int m=grid[0].size();
            int n=grid.size();
            vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
      (m, 0));

      for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
          if (j1 == j2)
            front[j1][j2] = grid[n - 1][j1];
          else
            front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
      }

      //Outer Nested Loops for travering DP Array
      for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
          for (int j2 = 0; j2 < m; j2++) {

            int maxi = INT_MIN;

            //Inner nested loops to try out 9 options
            for (int di = -1; di <= 1; di++) {
              for (int dj = -1; dj <= 1; dj++) {

                int ans;

                if (j1 == j2)
                  ans = grid[i][j1];
                else
                  ans = grid[i][j1] + grid[i][j2];

                if ((j1 + di < 0 || j1 + di >= m) ||
                  (j2 + dj < 0 || j2 + dj >= m))

                  ans += -1e9;
                else
                  ans += front[j1 + di][j2 + dj];

                maxi = max(ans, maxi);

              }
            }
            cur[j1][j2] = maxi;
          }
        }
        front = cur;
      }

      return front[0][m - 1];
    }
};
```
