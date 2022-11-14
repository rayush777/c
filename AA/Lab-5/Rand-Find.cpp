#include <bits/stdc++.h>

using namespace std;

int R_Find(vector<int> arr, int k, int n)
{
    srand(time(NULL));
    int idx = rand() % n;
    // cout<<"idx-> "<<idx<<endl;
    int y = arr[idx];
    vector<int> A, B;

    // Partion

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < y)
            A.push_back(arr[i]);
        if (arr[i] > y)
            B.push_back(arr[i]);
    }

    int AL = A.size();
    if (AL == k - 1)
        return y;
    if (AL < k - 1)
        return (R_Find(B, k - (AL + 1), B.size()));
    else if (AL > k - 1)
        return (R_Find(A, k, AL));
}

int main()
{

    vector<int> arr = {2, 8, 3, 9, 7, 16, 4};
    int n = arr.size();
    int k = 5;
    int ans = R_Find(arr, k, n);
    cout << ans << endl;
}