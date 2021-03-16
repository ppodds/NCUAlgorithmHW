#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int times;
    cin >> times;
    vector<int> list;
    for (int i = 0; i < times; i++)
    {
        int a;
        cin >> a;
        list.push_back(a);
        sort(list.begin(), list.end());
        if (i != 0)
        {
            if ((i + 1) % 2 == 0)
            {
                cout << (list[(i+1)/2-1] + list[(i+1)/2])/2 << endl;
            }
            else
            {
                cout << list[(i+1)/2] << endl;
            }
        }
        else
            cout << a << endl;
    }
    return 0;
}