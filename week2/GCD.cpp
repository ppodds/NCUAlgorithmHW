#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int times;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        int a, b;
        cin >> a >> b;
        int t;
        if (a<b)
            swap(a, b);
        while( b!=0 )
        {
            t = b;
            b = a%b;
            a = t;
        }
        cout << a << endl;
    }
    return 0;
}