#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int lengthOfLongest(vector<int> &A, int k);
};
Solution::Solution(){}

int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::lengthOfLongest(vector<int> &A, int k)
{
    unordered_map<int, int> mp;
    int sum (0);
    int maxlen (0);
    for(int iter = 0; iter < A.size(); iter++)
    {
        sum = sum + A[iter];
        if(sum == k)
        {
            maxlen =  iter+1;
        }
        if(mp.find(sum) == mp.end())
        {
            mp[sum] = iter;
        }
        if(mp.find(sum-k) != mp.end())
        {
            if(maxlen < (iter - mp[sum-k]))
            {
                maxlen = max(maxlen , iter - mp[sum-k]);
            }
        }
    }
    return maxlen;
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
        int k;
        cin >> k;
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.lengthOfLongest(A, k);
        cout << ans <<endl;
    }
    return 0;
}
