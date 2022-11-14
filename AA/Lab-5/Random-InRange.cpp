#include <bits/stdc++.h>
using namespace std;

int RandomInRange(int s, int e)
{
    srand(time(NULL));
    int rn = s + rand() % (s - e + 1);
    return rn;
}

int main()
{
}