//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
        vector<vector<int>>vis(N+1,vector<int>(N+1,0));
        int dx[8] = {2,1,2,-1,-2,-2,-1,1};
        int dy[8] = {-1,2,1,2,1,-1,-2,-2};
        
        vis[KnightPos[0]][KnightPos[1]] = 1;
        queue<pair<pair<int,int>,int>>q; //{{x,y},cost}
        
        q.push({{KnightPos[0],KnightPos[1]},0});
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int k = q.front().second;
            q.pop();
            if(x==TargetPos[0] && y==TargetPos[1]){
                return k;
            }
            
            for(int i = 0;i<8;i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                
                if(nx>0 && nx<=N && ny>0 && ny <= N){
                    if(!vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push({{nx,ny},k+1});
                    }
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends