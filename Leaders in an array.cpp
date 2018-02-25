#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> leaders(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution :: leaders(vector<int> &A)
{
    vector<int> res;

    for(int iter = 0; iter < A.size()-1; iter++)
    {
        int max = A[iter];
        for(int jter = iter +1; jter < A.size(); jter++)
        {
            if(A[jter] > max)
            {
                max = A[jter];
            }
        }
        res.push_back(max);
    }
    res.push_back(A[A.size()-1]);
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
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
        vector<int> ans = sol.leaders(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
