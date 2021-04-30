#include <iostream>
#include <vector>

using namespace std;


void seq_dig(int num)
{
    vector<int> ans;
    if (num > 1)
    {
        for (int tst_dig = 9; tst_dig > 1; tst_dig--)
        {
            while (num != 1)
            {
                if (num % tst_dig)
                {
                    break; 
                }
                else
                {
                    num /= tst_dig;
                    ans.push_back(tst_dig);
                }
            }
        }
        if (num == 1)
        {
            for (int i=ans.size()-1;i>=0;i--)
                cout << ans[i];
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    else
    {
        if (num == 0)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
}

int main()
{
    int num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        seq_dig(num);
    }
    return 0;
}
