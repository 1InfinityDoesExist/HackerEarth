#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<char> > cross(vector<vector<char> > &vc);
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


bool isValid(int iter, int jter, int row, int col ,vector<vector<char> > &vc)
{
    if(iter < 0 || jter < 0 || iter >= row || jter >= col || vc[iter][jter] == 'X' || vc[iter][jter] == 'O')
    {
        return false;
    }
    return true;
}
Solution::Solution(){}

void bfs(int iter, int jter , vector<vector<char> > &vc)
{
     int row = vc.size();
    int col = vc[0].size();
    queue<pair<int, int> > q;
    q.push(make_pair(iter, jter));
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        vc[temp.first][temp.second] = 'O';
        for(int iter = 0; iter < 4; iter++)
        {
            int x = temp.first + dx[iter];
            int y = temp.second + dy[iter];

            if(isValid(x, y, row, col, vc))
            {
                q.push(make_pair(x, y));
            }
        }
    }
    return;
}
vector<vector<char> > Solution::cross(vector<vector<char> > &vc)
{
    int row = vc.size();
    int col = vc[0].size();
    if(row == 1 || col == 1)
    {
         for(int iter = 0; iter < vc.size(); iter++)
        {
           for(int jter = 0; jter < vc[iter].size() ;jter++)
           {
               if(vc[iter][jter] == '-')
               {
                   vc[iter][jter] = 'O';
               }
           }
        }
        return vc;
    }

    for(int iter = 0; iter < row; iter++)
    {
        if(vc[iter][0] == '-')
        {
            bfs(iter, 0, vc);
        }
    }
    for(int jter = 1; jter < col ;jter++)
    {
        if(vc[0][jter] == '-')
        {
            bfs(0, jter, vc);
        }
    }
    for(int jter = 1; jter < col ;jter++)
    {
        if(vc[row-1][jter] == '-')
        {
            bfs(row-1, jter, vc);
        }
    }
   for(int iter = 1; iter < row-1; iter++)
   {
       if(vc[iter][col-1] == '-')
       {
           bfs(iter,col-1, vc);
       }
   }

   for(int iter = 0; iter < vc.size(); iter++)
   {
       for(int jter = 0; jter < vc[iter].size() ;jter++)
       {
           if(vc[iter][jter] == '-')
           {
               vc[iter][jter] = 'X';
           }
       }
   }
   return vc;
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
        vector<vector<char> > vc;
        for(int iter = 0; iter < row; iter++)
        {
            vector<char> temp;
            for(int jter = 0; jter < col; jter++)
            {
                char ch;
                cin >> ch;
                if(ch == 'O')
                {
                    ch = '-';
                }
                temp.push_back(ch);
            }
            vc.push_back(temp);
        }
    //---------------------------------------------------
/*
     for(int iter = 0; iter < vc.size(); iter++)
        {
            for(int jter = 0; jter < vc[iter].size(); jter++)
            {
                cout << vc[iter][jter] << " ";
            }
          cout << endl;
        }
        cout << endl;
        //===========================================================*/

       vector<vector<char>> ans = sol.cross(vc);

        for(int iter = 0; iter < ans.size(); iter++)
        {
            for(int jter = 0; jter < ans[iter].size(); jter++)
            {
                cout << ans[iter][jter] << " ";
            }
      //    cout << endl;
        }
        cout << endl;
    }
    return 0;
}
