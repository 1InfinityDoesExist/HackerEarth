#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > change(vector<vector<int> > &A, int x, int y , int k);
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int iter, int jter, int row, int col)
{
    if(iter < 0 || jter < 0 || iter >= row || jter >= col)
    {
        return false;
    }
    return true;
}
Solution::Solution(){}
void bfs(int x, int y, int k, vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    int del = A[x][y];
    while(!q.empty())
    {
        pair<int , int> temp = q.front();
        q.pop();
        A[temp.first][temp.second] = k;
        for(int iter = 0; iter < 8; iter++)
        {
            int x_new = temp.first + dx[iter];
            int y_new = temp.second + dy[iter];
            if(isValid(x_new, y_new, row, col))
            {
                if(A[x_new][y_new] == del)
                {
                    q.push(make_pair(x_new, y_new));
                }
            }
        }

    }
    return;
}

vector<vector<int> > Solution :: change(vector<vector<int> > &A, int x, int y, int k)
{
    bfs(x, y, k, A);
    return A;
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
        int row;
        cin >> row;
        int col;
        cin >> col;
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
        /*for(int iter = 0; iter < A.size(); iter++)
        {
            for(int jter = 0; jter < A[iter].size(); jter++)
            {
                cout << A[iter][jter] << " ";
            }
            cout << endl;
        }
        cout  <<endl;*/
        int x, y, k;
        cin >> x >> y >> k;
        vector<vector<int> > ans = sol.change(A, x, y, k);
        for(int iter = 0; iter < ans.size(); iter++)
        {
            for(int jter = 0; jter < ans[iter].size(); jter++)
            {
                cout << ans[iter][jter] << " ";
            }
          //  cout << endl;
        }
        cout << endl;
    }
    return 0;
}
