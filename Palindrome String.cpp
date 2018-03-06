#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int palindromeOrNot(string str);
};
Solution::Solution(){}
static bool isPalin(string::iterator low, string::iterator high)
{
    while(low < high)
    {
        if(*low != *high)
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
int Solution::palindromeOrNot(string str)
{
    int low = 0;
    int high = str.length()-1;
    if(isPalin(str.begin()+low, str.begin()+high))
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;


        string str;
        cin >> str;
        int ans = sol.palindromeOrNot(str);
        if(ans == 1)
        {
            cout << "Palindrome" <<endl;
        }
        else
        {
            cout << "Not Palindrome" <<endl;
        }

    return 0;
}
