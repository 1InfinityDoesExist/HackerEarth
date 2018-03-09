#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        unsigned long long int longestVowel(string str);
};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
bool isValid(char c)
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;
    if(mp.find(c) == mp.end())
    {
        return false;
    }
    return true;
}
unsigned long long int Solution::longestVowel(string str)
{
   int count (0);
   int mx (0);
   for(string::size_type iter = 0; str[iter]; iter++)
   {
       if(isValid(str[iter]))
       {
            count++;
       }
       else
       {
           count = 0;
       }
       mx = max(mx, count);
   }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;

    string str;
    cin >> str;
    unsigned long long int ans = sol.longestVowel(str);
    cout << ans << endl;
    return 0;
}
