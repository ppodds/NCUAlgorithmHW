#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int packets[6], residual[6] = {};
        for (int i=0;i<6;i++)
            cin >> packets[i];
        bool flag = false;
        for (int i=0;i<6;i++)
            if (packets[i] != 0)
                flag = true;
        if (!flag)
            break;
        
        int ans = packets[5] + packets[4] + packets[3];
        residual[0] += packets[4] * 11;
        residual[1] += packets[3] * 5;
        ans += packets[2] / 4;
        packets[2] %= 4;
        residual[2] = packets[2];

        if (residual[2] == 1)
            residual[2] = 0, residual[0] += 7, residual[1] += 5, ans ++;
        else if (residual[2] == 2)
            residual[2] = 0, residual[0] += 6, residual[1] += 3, ans ++;
        else if (residual[2] == 3)
            residual[2] = 0, residual[0] += 5, residual[1] += 1, ans ++;

        if (residual[1] >= packets[1])
            residual[1] -= packets[1], packets[1] = 0;
        else
            packets[1] -= residual[1], residual[1] = 0;

        ans += packets[1] / 9;
        packets[1] %= 9;
        if (packets[1] > 0)
           residual[0] += 36 - packets[1] * 4, packets[1] = 0, ans ++; 
        else residual[0] += residual[1] * 4, residual[1] = 0;
         
        if (residual[0] >= packets[0])
           residual[0] -= packets[0], packets[0] = 0;
        else
           packets[0] -= residual[0], residual[0] = 0;

        ans += packets[0] / 36;
        packets[0] %= 36;

        if (packets[0] > 0)
            ans++;
        cout << ans << endl;
    }
    return 0;
}