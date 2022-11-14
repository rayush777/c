// Load Balancing Greedy

#include <bits/stdc++.h>
using namespace std;

void LoadBalancing(int jobs, int machine, vector<int> &time)
{
    vector<vector<int>> ans(machine);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; machine; i++)
    {
        pq.push({i, 0});
    }

    for (int i = 0; i < jobs; i++)
    {
        pair<int, int> x = pq.top();
        pair<int, int> x1 = make_pair(i, x.second + time[i]);
        pq.pop();
        ans[x.first].push_back(i);
        pq.push(x1);
    }

    cout << "Job will be assign in following way" << endl;
    for (int i = 0; i < machine; i++)
    {
        cout << "On machine " << i + 1 << " ";
        for (auto x : ans[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int jobs, machine;
    cin >> jobs >> machine;

    vector<int> time(jobs);

    for (auto &x : time)
        cin >> x;

    LoadBalancing(jobs, machine, time);

    return 0;
}
