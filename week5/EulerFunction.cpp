#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int times;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        int n;
        cin >> n;
        int amount = 1;
        for (int j=2;j<n;j++)
        {
            int t;
            int a = n;
            int b = j;
            while( b!=0 )
            {
                t = b;
                b = a%b;
                a = t;
            }
            if (a == 1)
                amount++;
        }
        cout << amount << endl;
    }
    return 0;
}