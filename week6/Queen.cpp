#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1==0 && y1==0 && x2==0 && y2==0)
            break;

        bool board[8][8] = {false};
        
        if (x1 == x2 || y1 == y2)
        {
            cout << "True" << endl;
            continue;
        }
        else
        {
            
            int xd = abs(x1-x2);
            int yd = abs(y1-y2);
            if (xd == yd)
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
    }
    return 0;
}