//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {   
        //Basic approach ye hai ki pehle dekho ki jo boundary pr
        //"o" hai toh vo abhi covert nhi ho payenge "x" m 
        //or jo us se connected  hai boundary wale "O" se vo bhi nhi
        //ho payenge , isliye pehle  dekh lo boundary pr koi "o" toh
        //nhi hai, if hai toh usko temporary t maan lo or jo bhi us
        //se coonected hai usko bhi t mark kr do or baaki
        //phir jo ab bche honge vo toh "x" may convert ho hi skty hai
        //so last may jb array pr traverse krenge toh jo "o" hai usko
        //x may convert kr denge or jo "t" marked ho rkhe hai usko
        //"o" may hi rhna do.


        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if((i == 0 || j == 0 || i == n-1 ||
                j == m-1) && mat[i][j] == 'O'){
                    
                    mat[i][j] = 'T';
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int x = front.first;
            int y = front.second;
            
            int dx[4] = {0, -1, 0, 1};
            int dy[4] = {-1, 0, 1, 0};
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m
                && mat[nx][ny] == 'O'){
                    mat[nx][ny] = 'T';
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
                else if(mat[i][j] == 'T'){
                    mat[i][j] = 'O';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends