#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while (true)
    {
        long long a,b;
        cin >> a;
        if (a == 0)
            break;
        cin >> b;
        if (a > b)
            cout << ">" << endl;
        else if (a == b)
            cout << "=" << endl;
        else
            cout << "<" << endl;
    }
    return 0;
}