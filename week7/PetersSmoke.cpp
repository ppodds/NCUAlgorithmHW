#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int a=0;a<N;a++)
    {
        long long k, n;
        cin >> k >> n;
        long long sum = n;
        while (n >= k)
        {
            sum += n / k;
            n = n % k + n / k;
        }
        cout << sum << endl;
    }
    return 0;
}