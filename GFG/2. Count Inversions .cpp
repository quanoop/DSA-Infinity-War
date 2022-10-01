// Q:

// Comments

// Initial Instinct

// Solution Code
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], int s, int m, int e)
    {
        long long n1 = m - s + 1;
        long long n2 = e - m;
        long long count = 0;
        long long A[n1];
        long long B[n2];
        for (long long i = 0; i < n1; i++)
        {
            A[i] = arr[s + i];
        }
        for (long long i = 0; i < n2; i++)
        {
            B[i] = arr[m + 1 + i];
        }
        long long i = 0, j = 0, k = s;
        while (i < n1 and j < n2)
        {
            if (A[i] > B[j])
            {
                count += n1 - i;
                arr[k] = B[j];
                j++;
            }
            else
            {
                arr[k] = A[i];
                i++;
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
        return count;
    }
    void mergeSort(long long arr[], long long s, long long e, long long &c)
    {
        if (s < e)
        {
            long long m = s + (e - s) / 2;
            mergeSort(arr, s, m, c);
            mergeSort(arr, m + 1, e, c);
            c += merge(arr, s, m, e);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long c = 0;
        mergeSort(arr, 0, N - 1, c);
        return c;
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends

// Optimised solution

// FeedBack and more