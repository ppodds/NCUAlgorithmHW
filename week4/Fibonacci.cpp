#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> f = {1, 1};
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        int size = f.size();
        if (size < input)
            while (size < input)
            {
                f.push_back(f[size-2] + f[size-1]);
                size++;
            }
        cout << f[input-1] << endl;
    }
    return 0;
}