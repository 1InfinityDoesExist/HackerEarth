#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int minimumCost(vector<vector<int> > &A);
};
Solution::Solution(){}

pair<int , int> source;
pair<int, int > destination;
map<pair<int, int> , pair<int, int> > mp;
set<pair<pair<int, int> , int> > st;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isValid(int x, int y, int M, int N)
{
    if(x < 0 || y < 0 || x >= M || y >= N)
    {
        return false;
    }
    return true;
}
/*
void display()
{
    stack<pair<int, int> > s;
    while(destination != source)
    {
        s.push(destination);
        destination = mp[destination];
    }
    s.push(source);

    while(!s.empty())
    {
        pair<int, int> nikal = s.top();
        s.pop();
        int x = nikal.first;
        int y = nikal.second;
    }
    return;
}
*/
int Solution::minimumCost(vector<vector<int> > &A)
{
   int dp[A.size()][A.size()];
   for(unsigned int iter = 0; iter < A.size(); iter++)
   {
       for(unsigned int jter = 0; jter < A.size(); jter++)
       {
           dp[iter][jter] = INT_MAX;
       }
   }

   int n = A.size();
   source = make_pair(0 , 0);
   destination = make_pair(n-1, n-1);

   st.insert(make_pair(source, 0));
   dp[0][0] = A[0][0];

   while(!st.empty())
   {
       pair<pair<int, int> , int > temp = *st.begin();
       st.erase(st.begin());
       int ct = temp.second;
       pair<int, int> p = temp.first;
       int x = p.first;
       int y = p.second;

       if(x == destination.first && y == destination.second)
       {
           return dp[n-1][n-1];
       }
       for(int iter = 0; iter < 4; iter++)
       {
           int new_x = x + dx[iter];
           int new_y = y + dy[iter];

           if(isValid(new_x, new_y, n , n))
           {
               if(dp[new_x][new_y] > dp[x][y] + A[new_x][new_y])
               {
                   if(dp[new_x][new_y] != INT_MAX)
                   {
                       st.erase(make_pair(make_pair(new_x, new_y), dp[new_x][new_y]));
                   }
                   dp[new_x][new_y] = dp[x][y] + A[new_x][new_y];
                   mp[make_pair(new_x, new_y)] = p;
                   st.insert(make_pair(make_pair(new_x, new_y), dp[new_x][new_y]));
               }
           }
       }
   }
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
        int n;
        cin >> n;
        vector<vector<int> > A;
        for(int iter = 0; iter < n ;iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            A.push_back(temp);
        }
        int ans = sol.minimumCost(A);
        cout << ans <<endl;
    }
    return 0;
}
