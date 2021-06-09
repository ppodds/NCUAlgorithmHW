#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    while (N!=0)
    {
        vector<int> e;
        for (int i=0;i<N;i++)
        {
            int w,h;
            cin >> w >> h;
            if (max(w, h)/4 >= min(w, h))
                e.push_back(min(w, h));
            else
            {
                if (min(w, h)/2 >= max(w, h)/4)
                    e.push_back(min(w, h)/2);
                else
                    e.push_back(max(w, h)/4);
            }
        }
        int ans;
        int t = 0;
        for (int i=N-1;i>=0;i--)
        {
            if (e[i] >= t)
            {
                ans = i+1;
                t = e[i];
            }
        }
        cout << ans << endl;
        cin >> N;
    }
    return 0;
}