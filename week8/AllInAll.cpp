#include <iostream>

using namespace std;

int main()
{
    string substring, teststring;
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++)
    {
        cin >> substring >> teststring;
        int index = 0;
        for (int i = 0; i < teststring.length(); i++)
        {
            if (teststring[i] == substring[index])
            {
                index++;
                if (index == substring.length())
                    break;
            }
        }
        if (index == substring.length())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}