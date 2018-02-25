#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> sorting(vector<int> &A, int x, int y);
};
Solution::Solution(){}
vector<int> Solution::sorting(vector<int> &A, int x, int y)
{
    if(x < y)
    {
        sort(A.begin()+x, A.begin()+y+1);
    }
   else
   {
       sort(A.begin()+y, A.begin()+x+1);
   }

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
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int x, y;
        cin >> x >> y;
        vector<int> ans = sol.sorting(A, x, y);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
