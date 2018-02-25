#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> wavearray(vector<int> &A);
};
Solution::Solution(){}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
vector<int> Solution::wavearray(vector<int> &A)
{
    sort(A.begin(), A.end());
    bool flag = true;
    for(int iter = 0; iter < A.size()-1; iter++)
    {
        if(flag)
        {
            if(A[iter] < A[iter+1])
            {
                swap(A[iter], A[iter+1]);
            }
        }
        else
        {
            if(A[iter] > A[iter+1])
            {
                swap(A[iter], A[iter+1]);
            }
        }
        flag = !flag;
    }
    return A;
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
        vector<int> ans = sol.wavearray(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
