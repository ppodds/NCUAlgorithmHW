#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &A, int start, int end)
{
    if (end - start >= 1)
    {
        int pivot;
        int left, right;

        pivot = A[start];
        left = start;
        right = end;

        while (true)
        {

            while (A[left] <= pivot && left < end)
            {
                left++;
            }

            while (A[right] > pivot)
            {
                right--;
            }

            if (right > left)
            {
                swap(A[left], A[right]);

                for (int i = 0; i < A.size(); i++)
                {
                    cout << A[i] << " ";
                }
                cout << endl;
            }
            else
            {
                if (right != 0)
                {
                    swap(A[start], A[right]);
                }
                break;
            }
        }

        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;

        quickSort(A, start, right - 1);
        quickSort(A, right + 1, end);
    }
}

int main()
{
    int n;

    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    quickSort(A, 0, n - 1);

    return 0;
}