#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*
* 這份是OJ上WA的，如果要抄請小心注意
* 
*/

int main() 
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        int N, amount;
        cin >> N >> amount;
        if (N == 0 && amount == 0)
            break;
        vector<int> type;
        for (int j=0;j<N;j++)
        {
            int tmp;
            cin >> tmp;
            type.push_back(tmp);
        }
        sort(type.begin(), type.end());
        int ans = INT32_MAX;
        for (int a=N-1;a>=0;a--)
        {
            int count = 0;
            int num = amount;
            for (int j=a;j>=0;j--)
            {
                count += num / type[j];
                num %= type[j];
            }
            if (count < ans)
                ans = count;
        }
        cout << ans << endl;
    }
    return 0;
}