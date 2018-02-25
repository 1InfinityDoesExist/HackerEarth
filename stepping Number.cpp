#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int steppingNumber(int n, int m);
};
Solution::Solution(){}
void  bfs(int n, int m, int num, vector<int> &res)
{
    queue<int> q;
    q.push(num);
    while(!q.empty())
    {
        int stepNum = q.front();
        q.pop();
        if(stepNum >= n && stepNum <= m)
        {
            //count++;
            res.push_back(stepNum);
        }

        if(stepNum == 0 || stepNum > m)
        {
            continue;
        }

        int lastDigit = stepNum %10;
        int stepNumA = stepNum*10 + (lastDigit-1);
        int stepNumB = stepNum*10 + (lastDigit+1);

        if(lastDigit == 0)
        {
            q.push(stepNumB);
        }
        else if(lastDigit == 9)
        {
            q.push(stepNumA);
        }
        else
        {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}
int Solution::steppingNumber(int n, int m)
{
    vector<int> res;
    for(int iter = 0; iter <= 9; iter++)
    {
        bfs(n , m, iter, res);
    }
    return res.size();
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
        int n, m;
        cin >> n >> m;
        int ans =sol.steppingNumber(n ,m);
        cout << ans << endl;
    }
    return 0;
}
