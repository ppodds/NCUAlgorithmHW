#include <iostream>

using namespace std;

int main()
{
    int Case;
    cin >> Case;

    for (int c = 1; c <= Case; c++)
    {
        int n, i, count = 0;
        char ch;
        cin >> n;
        getchar();

        for (i = 0; i < n; i++)
            if (getchar() == '.')
            {
                count++;
                i += 2;
                if (i < n)
                {
                    getchar();
                    getchar();
                }
            }

        getchar();
        cout << "Case " << c << ": " << count << endl;
    }

    return 0;
}