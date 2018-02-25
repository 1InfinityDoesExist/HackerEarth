#include<bits/stdc++.h>
using namespace std;

class Solution
{
  private:
  public:
    Solution();
    void bub(vector<int> &A);
};
Solution::Solution(){}
void Solution::bub(vector<int> &A)
{
    bool swapped = true;
    for(int pass = A.size()-2; pass >= 0 && swapped; pass--)
    {
        swapped = false;
        for(int iter = 0; iter <= pass; iter++)
        {
            if(A[iter] > A[iter+1])
            {
                int temp  = A[iter];
                A[iter] = A[iter+1];
                A[iter+1] = temp;
                swapped = true;
            }
        }
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        sol.bub(A);
        for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
