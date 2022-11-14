#include <bits/stdc++.h>

using namespace std;

int horspool(string text, string pattern, int n, int m)
{
    int m = pattern.length(), n = text.length();
    unordered_map<char, int> shift;

    for (int i = 0; i < 26; i++)
        shift['a' + i] = m;

    for (auto x : shift)
        cout << x << " ";

    for (int i = 0; i <= m - 2; i++)
        shift[pattern[i]] = m - 1 - i;

    int j = 0;
    while (j + m <= n)
    {
        if (pattern[m - 1] == text[j + m - 1])
        {
            int i = m - 2;
            while (i >= 0 and pattern[i] == text[j + i])
                i--;
            if (i == -1)
                return j;
            j += shift[text[j + m - 1]];
        }
    }
    return n;
}

int main()
{

    string text, pattern;
    // cin >> text >> pattern;

    return 0;
}