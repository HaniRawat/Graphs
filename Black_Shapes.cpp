void dfs(int r, int c, vector<string>&A, vector<vector<int>>&vis){
    int n = A.size();
    int m = A[0].size();
    int delr[] = {1, 0, -1, 0};
    int delc[] = {0, -1, 0, 1};
    
    for(int i=0; i<4; i++){
        int newr = r + delr[i];
        int newc = c + delc[i];
        
        if(newr >= 0 && newc >= 0 && newr < n &&
        newc < m && !vis[newr][newc] && A[newr][newc] == 'X'){
            vis[newr][newc] = 1;
            dfs(newr, newc, A, vis);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 'X' && !vis[i][j]){
                cnt++;
                vis[i][j] = 1;
                dfs(i,j,A,vis);
            }
        }
    }
    return cnt;
}