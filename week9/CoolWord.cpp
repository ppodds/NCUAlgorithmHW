#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int m;
        cin >> m;
        int ans = 0;
        for (int _=0;_<m;_++)
        {
            map<char, int> count;
            string input;
            cin >> input;
            for (char c : input)
            {
                if (count.find(c) != count.end())
                    count[c]++;
                else
                    count[c] = 1;
            }
            vector<int> nums;
            for (auto it = count.begin(); it != count.end(); it++) {
                nums.push_back(it->second);
            }
            sort(nums.begin(), nums.end());
            int tmp;
            tmp = nums[0];
            bool check = true;
            for (int j=1;j<nums.size();j++)
            {
                if (tmp == nums[j])
                {
                    check = false;
                    break;
                }
                tmp = nums[j];
            }
            if (check && nums.size() != 1)
            {
                ans++;
            }
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}