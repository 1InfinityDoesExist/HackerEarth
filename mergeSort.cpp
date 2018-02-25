#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void mergesort(vector<int> &A);
};
Solution::Solution(){}
void mergeSort(vector<int> &A, int low, int mid, int high)
{

    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = A[i+low];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = A[j+mid+1];
    }
    int iter = 0;
    int jter = 0;
    int kter = low;
    while(iter < n1 && jter < n2)
    {
        if(L[iter] <= R[jter])
        {
            A[kter] = L[iter];
            iter++;
        }
        else
        {
            A[kter] = R[jter];
            jter++;
        }
        kter++;
    }

    while(iter < n1)
    {
        A[kter] = L[iter];
        iter++;
        kter++;
    }
    while(jter < n2)
    {
        A[kter] = R[jter];
        kter++;
        jter++;
    }
    return;
}
void merge(vector<int> &A, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;
        merge(A, low, mid);
        merge(A, mid+1, high);
        mergeSort(A, low, mid, high);
    }
}
void Solution::mergesort(vector<int> &A)
{
    int low = 0;
    int high = A.size()-1;
    merge(A, low, high);
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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        sol.mergesort(A);
        for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
