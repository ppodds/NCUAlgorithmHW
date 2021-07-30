#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> ans(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for (int i = 1; i <= s1.length(); i++)
        {
            for (int j = 1; j <= s2.length(); j++)
            {
                if (s1.at(i - 1) == s2.at(j - 1))
                {
                    ans.at(i).at(j) = ans.at(i - 1).at(j - 1) + 1;
                }
                else
                {
                    ans.at(i).at(j) = max(ans.at(i - 1).at(j), ans.at(i).at(j - 1));
                }
            }
        }
        cout << ans.at(s1.length()).at(s2.length()) << endl;
    }
}