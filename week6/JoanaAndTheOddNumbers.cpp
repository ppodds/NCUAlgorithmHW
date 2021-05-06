#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        long long N;
        cin >> N;
        long long end = (1+N) * (N/2+1) - 1;
        cout << (end - 4) * (end -2) * end << endl;
    }
    return 0;
}