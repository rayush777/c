// Rabin Karp Algorithm
#include <bits/stdc++.h>

using namespace std;

#define d 10

void Rabin_Karp(string pattern, string text, int q)
{
    int n = text.length(), m = pattern.length();
    int i, j, p = 0, t = 0, h = 1;

    /*
        t = ((d * (t - v[character to be removed] * h) + v[character to be added] mod 13
        Where, h = dm-1
    */

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i < n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                cout << "Match @= " << i + 1 << endl;
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int q = 13;
    Rabin_Karp(pattern, text, q);

    return 0;
}