#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> rotating(vector<int> &A, int kth);
};
Solution::Solution(){}
vector<int> Solution::rotating(vector<int> &A, int kth)
{
    int len = kth%A.size();
    rotate(A.begin(), A.begin()+len, A.end());
    /*
    for(int iter = 1; iter <= (kth%A.size()); iter++)
    {
        rotate(A.begin(), A.begin()+1, A.end());
    }*/
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
        int kth;
        cin >> kth;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.rotating(A, kth);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
