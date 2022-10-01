// Q:

// Comments

// Initial Instinct

// Solution Code
class Solution
{
public:
    void merge(vector<int> &arr, int s, int m, int e)
    {
        int n1 = m - s + 1;
        int n2 = e - m;
        vector<int> A;
        vector<int> B;
        for (int i = 0; i < n1; i++)
        {
            A.push_back(arr[s + i]);
        }
        for (int i = 0; i < n2; i++)
        {
            B.push_back(arr[m + 1 + i]);
        }
        int i = 0, j = 0, k = s;
        while (i < n1 and j < n2)
        {
            if (A[i] < B[j])
            {
                arr[k] = A[i];
                i++;
            }
            else
            {
                arr[k] = B[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = A[i];
            k++;
            i++;
        }

        while (i < n2)
        {
            arr[k] = B[j];
            k++;
            j++;
        }
    }
    void mergeSort(vector<int> &arr, int s, int e)
    {
        if (s < e)
        {
            int m = s + (e - s) / 2;
            mergeSort(arr, s, m);
            mergeSort(arr, m + 1, e);
            merge(arr, s, m, e);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Optimised solution
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int s, int e)
{

    int pivot = a[e];
    int i = s - 1;

    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(vector<int> &a, int s, int e)
{
    // Base Case
    if (s >= e)
    {
        return;
    }
    // Rec Case
    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    cout << arr.size() << endl;
    int n = arr.size();

    quicksort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
// Any other sorting technique can also be implemented where complexity is O(nlogn)

// FeedBack and more