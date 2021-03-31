#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        long long sum;
        cin >> sum;
        for (long long j=sqrt(sum);;j++)
        {
            long long diff = j*(1+j)/2 - sum;
            if (diff > 0)
                if (1<=diff && diff <=j)
                {
                    cout << j << " " << diff << endl;
                    break;
                }
        }
    }
    return 0;
}