#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<char> nonRepeatingChar(vector<char> &A);
};
Solution::Solution(){}
vector<char> Solution::nonRepeatingChar(vector<char> &A)
{
    map<char, int> mp;
    vector<char> res;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
        bool mila = true;
        for(int jter = 0; jter <= iter ; jter++)
        {
            if(mp[A[jter]] == 1)
            {
                mila = false;
                res.push_back(A[jter]);
                break;
            }
        }
        if(mila)
        {
            res.push_back('1');
        }
    }
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
        vector<char> A;
        for(int iter = 0; iter < n ;iter++)
        {
            char ch;
            cin >> ch;
            A.push_back(ch);
        }
        vector<char> ans = sol.nonRepeatingChar(A);
        for(int iter = 0; iter < ans.size(); iter++)
        {
            if(ans[iter] == '1')
            {
                cout << "-1" << " ";
            }
            else
            {
                cout << ans[iter] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
