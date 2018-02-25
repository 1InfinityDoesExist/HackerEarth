#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int minPoints(vector<vector<int> > &A);
};
Solution::Solution(){}
int min(int x, int y)
{
    return x < y ? x : y;
}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::minPoints(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    int dp[row][col];
    int m = row;
    int n = col;
    dp[m-1][n-1] = A[m-1][n-1] > 0 ? 1 : abs(A[m-1][n-1]) + 1;

    for(int iter = m-2; iter >=0; iter--)
    {
        dp[iter][n-1] = max(dp[iter+1][n-1] - A[iter][n-1], 1);
    }
    for(int jter = n-2; jter >= 0; jter--)
    {
        dp[m-1][jter] = max(dp[m-1][jter+1] - A[m-1][jter], 1);
    }
    for(int iter = m-2; iter >= 0; iter--)
    {
        for(int jter = n-2; jter >= 0; jter--)
        {
            int dekh = min(dp[iter][jter+1],  dp[iter+1][jter]);
            dp[iter][jter] = max(dekh - A[iter][jter], 1);
        }
    }
    return dp[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int> > A;
        for(int iter = 0; iter < row; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < col; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            A.push_back(temp);
        }
        int ans = sol.minPoints(A);
        cout << ans << endl;
    }
    return 0;
}
