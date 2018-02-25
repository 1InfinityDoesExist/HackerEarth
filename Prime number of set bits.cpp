#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
class Solution
{
    private:
    public:
        Solution();
        void primeCalculator();
        int checkCount(int L, int R);
};
Solution::Solution(){}
void Solution::primeCalculator()
{
    int dp[200];
    memset(dp, 0, sizeof(dp));
    for(int iter = 2; iter <= sqrt(200); iter++)
    {
        if(dp[iter] == 0)
        {
            prime.push_back(iter);
            for(int jter = 2*iter; jter <= 200; jter = jter+iter)
            {
                dp[jter] = 1;
            }
        }
    }
    return;
}
bool isValid(int iter)
{
    /*
    string str = "";
    while(iter != 0)
    {
        str = ((iter%2 == 0) ? "0" : "1") + str;
        iter /= 2;
    }
    bitset<64>foo(str);
    int setBits = foo.count();*/
    int count (0);
    while(iter != 0)
    {
        if(iter%2 == 1)
        {
            count++;
        }
        iter /= 2;
    }
    if(find(prime.begin(), prime.end(), count) != prime.end())
    {
        return true;
    }
    return false;

}
int Solution::checkCount(int L, int R)
{
    int count (0);
    for(int iter = L; iter <= R; iter++)
    {
        if(isValid(iter))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.primeCalculator();
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int L, R;
        cin >> L >> R;
        int ans = sol.checkCount(L, R);
        cout << ans << endl;
    }
    return 0;
}
