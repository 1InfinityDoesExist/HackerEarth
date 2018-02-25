#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void permuation(string str, int low, int high);
};
Solution::Solution(){}
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void Solution::permuation(string str, int low, int high)
{
    if(low == high)
    {
        cout << str << endl;
        return;
    }
    else
    {
        for(int iter = low; iter <= high; iter++)
        {
            swap(str[low], str[iter]);
            permuation(str, low+1, high);
            swap(str[low], str[iter]);
        }
    }
    return;
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

        sol.permuation(str, 0 , str.length()-1);
    }
    return 0;
}
