#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int countOccurence(string str, int n);
};
Solution::Solution(){}
int Solution::countOccurence(string str, int n)
{
    int count (0);
    str.erase(unique(str.begin(), str.end()), str.end());
    map<char, int> mp;
    for(string::size_type iter = 0; iter < str.length() ;iter++)
    {
        mp[str[iter]]++;
    }
    for(map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second == n)
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
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        string str;
        cin >> str;
        int n;
        cin >> n;
        int ans = sol.countOccurence(str, n);
        cout << ans << endl;
    }
    return 0;
}
