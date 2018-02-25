#include<bits/stdc++.h>
using namespace std;

map<int, bool> primes;
class Solution
{
    private:
    public:
        Solution();
        vector<int> sophiePrime(int n);
};
Solution::Solution(){}
void primeNikal()
{
    int n = 100000;
    bool dp[n+1];
    memset(dp, true, sizeof(dp));
    for(int iter = 2; iter <= n; iter++)
    {
        if(dp[iter] == true)
        {
            primes[iter] = true;
            for(int jter = 2*iter; jter <= n; jter = jter+iter)
            {
                dp[jter] = false;
            }
        }
    }
}
vector<int> Solution::sophiePrime(int n)
{
    vector<int> ans;
    for(map<int,bool>::iterator iter = primes.begin(); iter != primes.end(); iter++)
    {
        if(iter->first < n)
        {
            int mila = (2*(iter->first) + 1);
            if(primes.find(mila) != primes.end())
            {
                ans.push_back(iter->first);

            }
        }

    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    primeNikal();
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<int> ans = sol.sophiePrime(n);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
