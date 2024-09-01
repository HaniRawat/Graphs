//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int n = hospital.size();
        int m = hospital[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(hospital[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        int dist = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            
            dist++;
            for(int i=0; i<size; i++){
                int n1 = q.front().first;
                int n2 = q.front().second;
                
                q.pop();
                
                for(int i=0; i<4; i++){
                    int newx = n1+dx[i];
                    int newy = n2+dy[i];
                    
                    if(newx>=0 && newx<n && newy>=0 && 
                    newy<m && hospital[newx][newy] == 1){
                        q.push({newx,newy});
                        hospital[newx][newy] = 2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
          for(int j=0;j<m;j++) {
              if(hospital[i][j] == 1) {
                  return -1;
                }
            }
        }
      return dist-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends