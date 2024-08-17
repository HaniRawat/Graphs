void dfs(vector<vector<int>> &v, vector<int> &A, vector<bool> &visited, int C, int &ans, int curr){
    if(visited[curr])
        return;
    visited[curr] = true;
    if(A[curr] == 1)
        C--; //count good nodes before limit
    if(C < 0)
        return;
    if(v[curr].size() == 1){ //is leaf node
        ans++;
        return;
    } 
    for(int i=0; i<v[curr].size(); i++){
        dfs(v, A, visited, C, ans, v[curr][i]);
    }
    
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<vector<int>> v(n, vector<int>{}); //adjacency list
    for(int i=0; i<B.size(); i++){
        v[B[i][0] - 1].push_back(B[i][1] - 1);
        v[B[i][1] - 1].push_back(B[i][0] - 1);
    }
    int ans = 0;
    vector<bool> visited(n, false);
    dfs(v, A, visited, C, ans, 0);
    return ans;
}