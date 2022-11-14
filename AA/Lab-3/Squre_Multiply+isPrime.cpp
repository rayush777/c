#include <bits/stdc++.h>
using namespace std;

vector<bool> ToBinaryArray(long long int num)
{
    vector<bool> b;
    while (0 < num)
    {
        b.push_back(1 & num);
        num >>= 1;
    }
    return b;
}

long long int power(long long int base, long long int exponent, long long int mod)
{
    long long res = 1;
    auto bin = ToBinaryArray(exponent);
    int len = bin.size();
    for (int i = len - 1; i >= 0; i--)
    {
        res = ((res % mod) * (res % mod)) % mod;
        if (true == bin[i])
            res = ((res % mod) * (base % mod)) % mod;
    }
    return res;
}

// T.C = O(K*log(n))

bool isPrime(long long int n, long long int k)
{
    srand(time(NULL));
    while (k > 0)
    {
        long long int a = (rand() % (n - 3)) + 2;
        if (__gcd(a, n) != 1)
            return false;
        long long int mod = 1e9 + 7;
        if (power(a, mod - 1, mod) != 1)
            return false;
        k--;
    }
    return true;
}

int main()
{
    long long int base, expo, mod = 1000000007;
    // cin >> base >> expo;

    long long int ans = isPrime(137, 100);

    if (ans)
        cout << "Number is Prime" << endl;
    else
        cout << "Number is Composite" << endl;
}