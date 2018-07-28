#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string goodBadAverage(const int n, const int k);
};
Solution::Solution(){}
string Solution::goodBadAverage(const int n, const int k)
{
    set<int> s;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        s.insert(data);
    }
    if(s.size() == k)
    {
        return "Good";
    }
    if(s.size() < k)
    {
        return "Bad";
    }
    if(s.size() > k)
    {
        return "Average";
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
        int k;
        cin >> k;
        string ans = sol.goodBadAverage(n, k);
        cout << ans << endl;
    }
    return 0;
}
