#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<double> items;

    for (long long _ = 0; _ < N; _++)
    {
        double tmp;
        cin >> tmp;
        items.push_back(tmp);
    }

    sort(items.begin(), items.end(), greater<int>());

    double capacity;
    int ans = 0;

    while (items.size() > 0)
    {
        capacity = 1;
        ans++;
        for (auto it = items.begin(); it != items.end();)
        {
            if (capacity > 0)
            {
                if (capacity >= *it)
                {
                    capacity -= *it;
                    it = items.erase(it);
                }
                else
                    it++;
            }
            else
                break;
        }
    }
    cout << ans << endl;
    
    return 0;
}