#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    while (N!=0)
    {
        vector<long long> city;
        for (long long i=0;i<N;i++)
        {
            long long element;
            cin >> element;
            city.push_back(element);
        }
        sort(city.begin(), city.end());
        for (long long i=0;i<N;i++)
            cout << city[i] << " ";
        cout << endl;
        cin >> N;
    }
    return 0;
}