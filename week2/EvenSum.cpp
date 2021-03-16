#include <iostream>

using namespace std;

int main()
{
    int times;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int j = a; j <= b; j++)
        {
            if (j % 2 == 0)
                sum += j;
        }
        cout << "Case " << i + 1 << ": " << sum << endl;
    }
    return 0;
}