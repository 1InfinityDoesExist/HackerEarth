#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int specialMatrix(vector<vector<int> > A);
};
Solution::Solution(){}
int Solution::specialMatrix(vector<vector<int> > A)
{
    int row = A.size();
    int col = A[0].size();
    if(A[0][0] == -1)
    {
        return 0;
    }
    for(int iter = 0; iter < row; iter++)
    {
        if(A[iter][0] == 0)
        {
            A[iter][0] = 1;
        }
        else
        {
            break;
        }
    }

    for(int jter = 1; jter < col ;jter++)
    {
        if(A[0][jter] == 0)
        {
            A[0][jter] = 1;
        }
        else
        {
            break;
        }
    }
    for(int iter = 1; iter < row; iter++)
    {
        for(int jter = 1; jter < col; jter++)
        {
            if(A[iter][jter] == -1)
            {
                continue;
            }
            if(A[iter-1][jter] > 0)
            {
                A[iter][jter] = (A[iter-1][jter] + A[iter][jter])%1000000007;
            }
            if(A[iter][jter-1] > 0)
            {
                A[iter][jter] = (A[iter][jter-1] + A[iter][jter])%1000000007;
            }
        }
    }

    return (A[row-1][col-1] > 0) ? A[row-1][col-1] : 0;
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
        int row, col, obs;
        cin >>  row >> col >> obs;
        vector<vector<int> > A;
        for(int iter = 0; iter < row; iter++)
        {
            vector<int> temp(col, 0);
            A.push_back(temp);
        }
        for(int iter = 0; iter < obs; iter++)
        {
            int x, y;
            cin >> x >> y;
            A[x-1][y-1] = -1;
        }
        int ans = sol.specialMatrix(A);
        cout << ans <<endl;
    }
    return 0;
}
