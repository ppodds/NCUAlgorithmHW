#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int a=0;a<N;a++)
    {
        int n;
        cin >> n;
        vector<int> container;
        int sum=0;
        for (int b=0;b<n;b++)
        {
            int t;
            cin >> t;
            sum += t;
            container.push_back(t);
        }
        int avg = sum/n;
        int ans = 0;
        for (int item : container)
        {
            if (item > avg)
                ans += item - avg;
        }
        cout << ans << endl;
    }
    return 0;
}