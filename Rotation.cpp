#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int kitnaTimeRotate(vector<int> &A);
};
Solution::Solution(){}
int Solution::kitnaTimeRotate(vector<int> &A)
{
    vector<int> cp = A;
    sort(cp.begin(), cp.end());

    int count (0);

    for(int iter = 1; iter <= A.size()-1; iter++)
    {
        if(A == cp)
        {
            break;
        }
        rotate(cp.rbegin(), cp.rbegin()+1, cp.rend());
        count++;
    }
    return count;
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
        int ans = sol.kitnaTimeRotate(A);
        cout << ans << endl;
    }
    return 0;
}
