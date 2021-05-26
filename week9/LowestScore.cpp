#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
    public:
        long long score;
        char className;
};

bool cmp(Student x, Student y){ return x.score<y.score;}


int main()
{
    long long N;
    cin >> N;
    for (long long i=0;i<N;i++)
    {
        long long k;
        cin >> k;
        vector<Student> a;
        bool flag = false;
        long long prev = -1;
        for (long long j=0;j<k;j++)
        {
            long long tmp;
            cin >> tmp;
            if (tmp < prev)
            {
                flag = true;
            }
            if (flag)
            {
                Student t;
                t.className = 'B';
                t.score = tmp;
                a.push_back(t);
            }
            else
            {
                Student t;
                t.className = 'A';
                t.score = tmp;
                a.push_back(t);
            }
            prev = tmp;
        }
        sort(a.begin(), a.end(), cmp);
        for (long long j=0;j<3;j++)
        {
            std::cout << a[j].className;
        }
        std::cout << endl;
    }
    return 0;
}