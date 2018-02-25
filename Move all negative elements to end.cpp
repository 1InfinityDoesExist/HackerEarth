#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> negativeToEnd(vector<int> &A, vector<int> &B);
};
Solution::Solution(){}
vector<int> Solution::negativeToEnd(vector<int> &A, vector<int> &B)
{
    for(vector<int>::iterator iter = B.begin(); iter != B.end(); iter++)
    {
        A.push_back(*iter);
    }
    B.clear();
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
        vector<int> pos;
        vector<int> neg;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            if(data < 0)
            {
                neg.push_back(data);
            }
            else
            {
                pos.push_back(data);
            }
        }
        vector<int> ans = sol.negativeToEnd(pos, neg);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
