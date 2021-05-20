#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maxFloors(const vector<long long> &a, const vector<long long> &b)
{
    long long aIndex = 0, bIndex = 0;
    long long count = 0;
    while (aIndex != a.size())
    {
        count++;
        bool finded = false;
        while (bIndex != b.size())
        {
            if (b[bIndex] > a[aIndex])
            {
                finded = true;
                count++;
                break;
            }
            else
                bIndex++;
        }
        if (finded)
            while (a[aIndex] <= b[bIndex] && aIndex != a.size())
                aIndex++;
        else
            return count;
    }
    return count;
}

int main()
{
    int p;
    cin >> p;
    for (int _ = 0; _ < p; _++)
    {
        long long floors;
        cin >> floors;
        vector<long long> blue;
        vector<long long> red;
        for (long long __ = 0; __ < floors; __++)
        {
            long long tmp;
            cin >> tmp;
            if (tmp > 0)
                blue.push_back(abs(tmp));
            else
                red.push_back(abs(tmp));
        }
        sort(blue.begin(), blue.end());
        sort(red.begin(), red.end());

        if (blue[0] > red[0])
            cout << maxFloors(red, blue) << endl;
        else
            cout << maxFloors(blue, red) << endl;

    }

    return 0;
}