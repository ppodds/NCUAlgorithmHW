#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector<int> &A, int n)
{
    int count = 0;
    for (int i=1;i<n;i++)
    {
        int j = i-1;
        int t = A[i];
        while (t<A[j] && j>=0)
        {
            A[j+1] = A[j];
            j--;
            count++;
        }
        A[j+1] = t;
    }
    return count;
}

int main()
{
    int input;
    cin >> input;
    while (input!=0)
    {
        vector<int> A;
        for (int i=0;i<input;i++)
        {
            int element;
            cin >> element;
            A.push_back(element);
        }
        int count = insertionSort(A, input);
        cout << "Optimal swapping takes " << count << " swaps." << endl;
        cin >> input;
    }
    return 0;
}