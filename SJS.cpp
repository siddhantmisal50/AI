#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int profit[n];
    int deadlines[n];
    vector<pair<int, int>> pairs;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> deadlines[i];
    }
    for (int i = 0; i < n; i++)
    {
        pairs.push_back(make_pair(profit[i], deadlines[i]));
    }
    for (int i = 0; i < n; i++)
    {
        int a = pairs[i].first;
        int b = pairs[i].second;

        if (mp.find(b) == mp.end())
        {
            mp[b] = a;
        }
        else
        {
            if (a > mp[b])
            {
                mp[b] = a;
            }
        }
    }

    int sum = 0;

    for (auto x : mp)
    {
        sum += x.second;
    }

    cout << sum << endl;

    return 0;
}