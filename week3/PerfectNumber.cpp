#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> temp;
    for (int i=0;i<N;i++)
    {
        long long num;
        cin >> num;
        long long sum=1;
        for (long long j=2;j<sqrt(num);j++)
        {
            if (num%j==0)
                sum += j + num/j;
        }
        if (sum == num)
        {
            temp.push_back(num);
        }
    }
    for (int j=0;j<temp.size();j++)
        {
            if (j==temp.size()-1)
                cout << temp[j] << endl;
            else
                cout << temp[j] << " ";
        }
    return 0;
}