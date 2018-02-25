#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string danAlpha(string str);
};
Solution::Solution(){}
vector<int> changeToPrime(vector<int> &A, vector<int> &prime)
{
    vector<int> ans;
    for(int iter = 0; iter < A.size(); iter++)
    {
        int num = A[iter];
        if(find(prime.begin(), prime.end(), num) != prime.end())
        {
            ans.push_back(num);
            continue;
        }
        int x = num+1;
        int y = num-1;

        int a, b;
        while(x <= 122)
        {
            if(find(prime.begin(), prime.end(), x) != prime.end())
            {
               a = x;
               break;
            }
            x++;
        }
        while(y >= 65)
        {
            if(find(prime.begin(), prime.end(), y) != prime.end())
            {
                b = y;
                break;
            }
            y--;
        }

        if(abs(num-a) >= abs(num-b))
        {
            if(b != 0)
            {
                ans.push_back(b);
            }
            else
            {
                ans.push_back(a);
            }
        }
        else
        {
            ans.push_back(a);
        }
    }
 /*   for(int iter = 0; iter < ans.size(); iter++)
    {
        cout << ans[iter] << " ";
    }
    cout << endl;*/
    return ans;
}
string Solution::danAlpha(string str)
{
    vector<int> prime;
    int dp[128];
    memset(dp, 0, sizeof(dp));
    for(int iter = 2; iter <= 122; iter++)
    {
        if(dp[iter] == 0)
        {
            if(iter >= 65 && iter <= 122)
            {
                prime.push_back(iter);
            }
            for(int jter = 2*iter; jter <= 122; jter = jter+iter)
            {
                dp[jter] = 1;
            }
        }
    }
    vector<int> alph;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        char c = str[iter];
     //   cout << c << " ";
        alph.push_back((int)c);
      //  cout << (int)c << " ";
    }
    cout << endl;
    vector<int> bdl = changeToPrime(alph, prime);//changing to prime number.......
    string s = "";
    for(int iter = 0; iter < bdl.size(); iter++)
    {
        int x = bdl[iter];
        s += char(x);
    }
    return s;
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
        string str;
        cin >> str;
        string ans = sol.danAlpha(str);
        cout << ans << endl;
    }
    return 0;
}
