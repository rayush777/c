#include <bits/stdc++.h>
using namespace std;

#define MOD 10e9 + 7;

vector<bool> ToBinaryArray(int k)
{
    vector<bool> b;
    while (k > 0)
    {
        b.push_back(k & 1);
        k = (k >> 1);
    }
    return b;
}

long long int power(long long int x, long long int k, long long int n)
{
    int res = 1;
    vector<bool> A = ToBinaryArray(k);
    int m = A.size();

    for (int i = m - 1; i >= 0; i--)
    {
        long long res = (res * res) % n;
        if (A[i] == true)
            res = (res * x) % n;
    }

    return res;
}

int main()
{

    long long int base, expo, mod = 1e9 + 7;
    cin >> base >> expo;

    cout << power(base, expo, mod);

    return 0;
}
