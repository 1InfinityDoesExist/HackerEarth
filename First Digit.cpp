#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int firstDigitOfProduct(vector<int> &A);
};
Solution::Solution(){}
int Solution::firstDigitOfProduct(vector<int> &A)
{
   double S = 0;
   for(int iter = 0; iter < A.size(); iter++)
   {
       S = S + log10(A[iter] * 1.0);
   }
   double fract_S = S - floor(S);
   int ans = pow(10, fract_S);
   return ans;
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.firstDigitOfProduct(A);
        cout << ans << endl;
    }
    return 0;
}
