void dfs(int row, int col, vector<vector<int>> &A, vector<vector<int>> &vis,int delrow[],int delcol[])
{
    vis[row][col] = 1;
    int n = A.size();
    int m = A[0].size();
   
    for(int i=0;i<4;i++)
    {
        int nrow= row + delrow[i];
        int ncol= col + delcol[i];
       
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
        {
            if(A[nrow][ncol]>=A[row][col] && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,A,vis,delrow,delcol);
            }
           
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> visB(n,vector<int>(m,0));
    vector<vector<int>> visR(n,vector<int>(m,0));
   
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    //first col
    for(int i=0;i<n;i++){
        if(!visB[i][0])
            dfs(i,0,A,visB,delrow,delcol);
    }
   
    //first row
    for(int j=0;j<m;j++){
        if(!visB[0][j])
            dfs(0,j,A,visB,delrow,delcol);
    }
   
    //last col
    for(int i=0;i<n;i++){
        if(!visR[i][m-1])
            dfs(i,m-1,A,visR,delrow,delcol);
    }
   
    //last row
    for(int j=0;j<m;j++){
        if(!visR[n-1][j])
            dfs(n-1,j,A,visR,delrow,delcol);
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visB[i][j] && visR[i][j])
                count++;
        }
    }
   
    return count;
}