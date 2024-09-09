//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

const int INF = INT_MAX;
    void hungarianAlgorithm(const vector<vector<int>>& costMatrix, vector<int>& assignment) 
    {
        int n = costMatrix.size();
        vector<int> u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0);
        for (int i = 1; i <= n; ++i) 
        {
            vector<int> minv(n + 1, INF);
            vector<bool> used(n + 1, false);
            int j0 = 0;
            p[0] = i;
            do 
            {
                used[j0] = true;
                int i0 = p[j0], delta = INF, j1;
                for (int j = 1; j <= n; ++j) 
                {
                    if (!used[j]) 
                    {
                        int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < minv[j]) 
                        {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta) 
                        {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }
                for (int j = 0; j <= n; ++j) 
                {
                    if (used[j]) 
                    {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    } 
                    else minv[j] -= delta;
                }
                j0 = j1;
            }while (p[j0] != 0);
            do 
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            }while (j0 != 0);
        }
        assignment.resize(n);
        for (int j = 1; j <= n; ++j) 
        {
            assignment[p[j] - 1] = j - 1;
        }
    }
    int assignmentProblem(int Arr[], int N) 
    {
        vector<vector<int>> costMatrix(N, vector<int>(N));
        int k=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                costMatrix[i][j]=Arr[k++];
            }
        }
        vector<int> assignment;
        hungarianAlgorithm(costMatrix, assignment);
        int minCost = 0;
        for (int i = 0; i < N; ++i) 
        {
            minCost += costMatrix[i][assignment[i]];
        }
        return minCost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        
        int Arr[n*n];
        for(int i=0; i<n*n; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.assignmentProblem(Arr,n) << endl;
    }
    return 0;
}
// } Driver Code Ends