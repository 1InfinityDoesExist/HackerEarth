#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        long long int converter(int n);
};
Solution::Solution(){}
long long int Solution::converter(int n)
{
    string str = "";
    while(n != 0)
    {
        str = ((n%2 == 0) ? "0" : "1") + str;
        n /= 2;
    }
    int len = str.length()+1;
    if(str.length()%2 != 0)
    {
        str = (len - str.length(), '0') + str;
    }
   for(int iter = 0; iter < str.length() ;iter = iter +2)
   {
       char c = str[iter];
       str[iter] = str[iter+1];
       str[iter+1] = c;
   }
   long long int decimal = bitset<120>(str).to_ulong();
   return decimal;
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
        long long int ans = sol.converter(n);
        cout << ans <<endl;
    }
    return 0;
}
