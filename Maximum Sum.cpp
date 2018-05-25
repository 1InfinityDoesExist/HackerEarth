#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxSumIncSubsequence(vector<int> &A);
};
Solution::Solution(){}
int Solution::maxSumIncSubsequence(vector<int> &A)
{
    int n = A.size();
    reverse(A.begin(), A.end());
    int *temp = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        temp[iter] = A[iter];
    }
    for(int iter = 1; iter < n; iter++)
    {
        for(int jter = 0; jter < iter; jter++)
        {
            if(A[iter] > A[jter] && temp[iter] < temp[jter] +A[iter])
            {
                temp[iter] = temp[jter] + A[iter];
            }
        }
    }
    int mx = 0;
    for(int iter = 0; iter < n; iter++)
    {
        if(mx < temp[iter])
        {
            mx = temp[iter];
        }
    }
    free(temp);
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<int> v;
    for(int iter = 0; iter < n ;iter++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }
    int ans = sol.maxSumIncSubsequence(v);
    cout << ans << endl;
    return 0;
}
