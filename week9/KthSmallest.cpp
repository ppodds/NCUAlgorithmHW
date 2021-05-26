#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        vector<int> v;
        for (int _=0;_<20;_++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int x;
        cin >> x;
        cout << v[x-1] << endl;
    }
    return 0;
}