#include <bits/stdc++.h>

using namespace std;

void SM(string P, string T)
{
    int n = T.length(), m = P.length();

    bool flag = 1;
    int i, j;
    for (i = 0; i < (n - m); i++)
    {
        for (j = 1; j < m; j++)
        {
            if (T[i + j] != P[j])
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1)
        cout << "Match @= " << i << endl;
}

int main()
{

    string T = "abcaaaxaa", P = "axa";

    SM(P, T);

    return 0;
}